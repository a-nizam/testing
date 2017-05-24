#include "importfromworddialog.h"
#include "ui_importfromworddialog.h"
#include "qzip.cpp"

ImportFromWordDialog::ImportFromWordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportFromWordDialog)
{

    ui->setupUi(this);
}

ImportFromWordDialog::~ImportFromWordDialog() {
    delete ui;
}

void ImportFromWordDialog::showEvent(QShowEvent *) {
    QComboBox *tests = ui->comboBoxTests;
    QComboBox *themes = ui->comboBoxThemes;
    DBConnection *dbConnection = &DBConnection::Instance();
    QSqlQuery *qQuery;
    int i;

    // clear fileds
    tests->clear();
    themes->clear();
    ui->lineEditFileBrowse->clear();

    // clear models
    testsList.clear();
    themesList.clear();
    testIdList.clear();
    themeIdList.clear();

    // select tests and themes to comboboxes
    if (dbConnection->sendQuery("SELECT ttype_id, ttype_name FROM ticket_type", qQuery)) {
        i = 0;
        while (qQuery->next()) {
            testIdList.append(qQuery->value(0).toInt());
            testsList.append(qQuery->value(1).toString());
            tests->addItem(testsList.at(i));
            i++;
        }
    }
    if (dbConnection->sendQuery(tr("SELECT thm_id, thm_name FROM theme WHERE thm_ttype=%1").arg(testIdList.at(0)), qQuery)) {
        i = 0;
        while (qQuery->next()) {
            themeIdList.append(qQuery->value(0).toInt());
            themesList.append(qQuery->value(1).toString());
            themes->addItem(themesList.at(i));
            i++;
        }
    }
}

void ImportFromWordDialog::on_pushButtonFileBrowse_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, QString(), QString(), tr("Microsoft Word (*.doc *.docx)"));
    ui->lineEditFileBrowse->setText(fileName);
    ui->lineEditFileBrowse->setCursorPosition(0);
}

int ImportFromWordDialog::unzipDocumentXml(QString _path) {
    _errno = 0;
    QZipReader *zip_reader = new QZipReader(_path);
    if (zip_reader->exists()) {
        QFile file("document.xml");
        if(file.open(QFile::WriteOnly)) {
            foreach (QZipReader::FileInfo info, zip_reader->fileInfoList()) {
                if (info.filePath == "word/document.xml") {
                    file.write(zip_reader->fileData(info.filePath), zip_reader->fileData(info.filePath).size());
                    file.close();
                    _errno = 1;
                    break;
                }
            }
        }
    }
    delete zip_reader;
    return _errno;
}

int ImportFromWordDialog::getQuestionTypeId(int _testId, int _cost) const {
    QSqlQuery *qQuery;
    int id = -1;
    if (DBConnection::Instance().sendQuery(tr("SELECT qtype_id FROM question_type WHERE qtype_ticket_type=%1 AND qtype_cost=%2").arg(_testId).arg(_cost), qQuery)) {
        while (qQuery->next()) {
            id = qQuery->value(0).toInt();
        }
    }
    return id;
}

void ImportFromWordDialog::on_pushButtonImport_clicked() {
    //    QComboBox *testsCombo = ui->comboBoxTests;
    //    QComboBox *themesCombo = ui->comboBoxThemes;
    QString line;
    unsigned short cost;
    int questionTypeId;
    QLineEdit *fileLine = ui->lineEditFileBrowse;
    int testId = testIdList.at(ui->comboBoxTests->currentIndex());
    int themeId = themeIdList.at(ui->comboBoxThemes->currentIndex());
    QString questionInsertQuery;
    QString answerInsertQuery;
    int isNoVariantQuestion;
    int questionCounter = 0;
    QSqlQuery *qQuery;
    int questionId;
    int answerIsCorrect;

    if (fileLine->text().length()) {
        if (unzipDocumentXml(fileLine->text())) {
            QFile *xmlFile = new QFile("document.xml");
            if (xmlFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
                QXmlStreamReader xmlStreamReader(xmlFile);
                _errno = DBConnection::Instance().db->transaction();
                if (_errno) {

                    while (!xmlStreamReader.atEnd() && !xmlStreamReader.hasError()) {
                        QXmlStreamReader::TokenType token = xmlStreamReader.readNext();
                        if (token == QXmlStreamReader::StartDocument)
                            continue;
                        if (token == QXmlStreamReader::StartElement) {
                            if (xmlStreamReader.name() == "t") {
                                line = xmlStreamReader.readElementText();

                                // if the line is question
                                if (line.at(0) == QUESTION_SYMBOL) {

                                    questionCounter++;

                                    while (line.right(1) != AND_OF_LINE_SYMBOL && !xmlStreamReader.atEnd() && !xmlStreamReader.hasError()) {
                                        QXmlStreamReader::TokenType qToken = xmlStreamReader.readNext();
                                        if (qToken == QXmlStreamReader::StartElement) {
                                            if (xmlStreamReader.name() == "t") {
                                                line += xmlStreamReader.readElementText();
                                            }
                                        }
                                    }
                                    line.chop(1);

                                    if (line.length() < SPECIAL_SYMBOL_MAX_COUNT) {
                                        _errno = 0;
                                        _errorMsg = tr("Недостаточная длина вопроса (Вопрос %1)").arg(questionCounter);
                                        break;
                                    }
                                    cost = line.at(QUESTION_COST_POSITION).digitValue();

                                    // rollback if there is no any question type for these params
                                    questionTypeId = getQuestionTypeId(testId, cost);
                                    if (questionTypeId == -1) {
                                        _errno = 0;
                                        _errorMsg = tr("Нет соответствия в справочнике Типы вопросов (Вопрос %1)").arg(questionCounter);
                                        break;
                                    }

                                    // determine if the question have variants
                                    isNoVariantQuestion = line.at(NO_VARIANT_SYMBOL_POSITION) == "@" ? 1 : 0;

                                    // clean info symbols of the line (3 if have no variant symbol)
                                    line.remove(0, isNoVariantQuestion ? SPECIAL_SYMBOL_MAX_COUNT : SPECIAL_SYMBOL_COUNT_WITH_VARIANTS);

                                    questionInsertQuery = tr("INSERT INTO question(q_content, q_theme, q_type, q_no_variants) VALUES('%1', %2, %3, '%4')").arg(line).arg(themeId).arg(questionTypeId).arg(isNoVariantQuestion ? 't' : 'f');

                                    if (DBConnection::Instance().sendQuery(questionInsertQuery, qQuery)) {
                                        questionId = qQuery->lastInsertId().toInt();
                                        delete qQuery;
                                    }
                                    else {
                                        _errno = 0;
                                        _errorMsg = tr("Не удалось добавить вопрос в базу данных (Вопрос %1)").arg(questionCounter);
                                        break;
                                    }
                                }
                                // if the line is answer
                                else {
                                    while (line.right(1) != AND_OF_LINE_SYMBOL && !xmlStreamReader.atEnd() && !xmlStreamReader.hasError()) {
                                        QXmlStreamReader::TokenType qToken = xmlStreamReader.readNext();
                                        if (qToken == QXmlStreamReader::StartElement) {
                                            if (xmlStreamReader.name() == "t") {
                                                line += xmlStreamReader.readElementText();
                                            }
                                        }
                                    }
                                    line.chop(1);

                                    answerIsCorrect = line.at(0) == "*" ? 1 : 0;

                                    if (answerIsCorrect) {
                                        line.remove(0, 1);
                                    }

                                    answerInsertQuery = tr("INSERT INTO answer(ans_content, ans_question, ans_is_correct) VALUES('%1', %2, '%3')").arg(line).arg(questionId).arg(answerIsCorrect ? 't' : 'f');

                                    if (DBConnection::Instance().sendQuery(answerInsertQuery, qQuery)) {
                                        delete qQuery;
                                    }
                                    else {
                                        _errno = 0;
                                        _errorMsg = tr("Не удалось добавить ответ в базу данных (Вопрос %1)").arg(questionCounter);
                                        break;
                                    }
                                }
                            }
                        }
                    }

                    if (_errno) {
                        if (DBConnection::Instance().db->commit()) {
                            QMessageBox::information(this, "Успешно", "Вопросы импортированы");
                        }
                        else {
                            QMessageBox::information(this, "Ошибка", "Не удалось сохранить тему");
                            DBConnection::Instance().db->rollback();
                        }
                    }
                    else {
                        DBConnection::Instance().db->rollback();
                        QMessageBox::information(this, "Ошибка", _errorMsg);
                    }
                }
                xmlFile->close();
                delete xmlFile;
            }
        }
    }
    else {
        QMessageBox::information(this, "Отказ", "Заполнены не все поля");
    }
}

void ImportFromWordDialog::on_comboBoxTests_activated(int index) {
    QComboBox *themes = ui->comboBoxThemes;
    DBConnection *dbConnection = &DBConnection::Instance();
    QSqlQuery *qQuery;
    int testId = testIdList.at(index);

    themes->clear();
    themesList.clear();
    themeIdList.clear();

    // select themes when test is changed
    if (dbConnection->sendQuery(tr("SELECT thm_id, thm_name FROM theme WHERE thm_ttype=%1").arg(testId), qQuery)) {
        int i = 0;
        while (qQuery->next()) {
            themeIdList.append(qQuery->value(0).toInt());
            themesList.append(qQuery->value(1).toString());
            themes->addItem(themesList.at(i));
            i++;
        }
    }
}
