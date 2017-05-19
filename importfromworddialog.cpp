#include "importfromworddialog.h"
#include "ui_importfromworddialog.h"
#include "qzip.cpp"

ImportFromWordDialog::ImportFromWordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportFromWordDialog),
    testsModel(new QStringListModel),
    themesModel(new QStringListModel)
{

    ui->setupUi(this);
}

ImportFromWordDialog::~ImportFromWordDialog() {
    delete ui;
}

void ImportFromWordDialog::showEvent(QShowEvent *) {
    // TODO: Заполнить поля теста и темы
}

void ImportFromWordDialog::on_pushButtonFileBrowse_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, QString(), QString(), tr("Microsoft Word (*.doc *.docx)"));
    ui->lineEditFileBrowse->setText(fileName);
    ui->lineEditFileBrowse->setCursorPosition(0);
}

int ImportFromWordDialog::unzipDocumentXml(QString _path) {
    int errno = 0;
    QZipReader *zip_reader = new QZipReader(_path);
    if (zip_reader->exists()) {
        QFile file("document.xml");
        if(file.open(QFile::WriteOnly)) {
            foreach (QZipReader::FileInfo info, zip_reader->fileInfoList()) {
                if (info.filePath == "word/document.xml") {
                    file.write(zip_reader->fileData(info.filePath), zip_reader->fileData(info.filePath).size());
                    file.close();
                    errno = 1;
                    break;
                }
            }
        }
    }
    delete zip_reader;
    return errno;
}

void ImportFromWordDialog::on_pushButtonImport_clicked() {
    QComboBox *testsCombo = ui->comboBoxTests;
    QComboBox *themesCombo = ui->comboBoxTheme;
    QLineEdit *fileLine = ui->lineEditFileBrowse;
    if (/*testsCombo->itemData(testsCombo->currentIndex()).toString().length() &
                            themesCombo->itemData(themesCombo->currentIndex()).toString().length() &*/
            fileLine->text().length()) {
        if (unzipDocumentXml(fileLine->text())) {
            QFile *xmlFile = new QFile("document.xml");
            if (xmlFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
                QXmlStreamReader xmlStreamReader(xmlFile);

                while (!xmlStreamReader.atEnd() && !xmlStreamReader.hasError())
                {
                    QXmlStreamReader::TokenType token = xmlStreamReader.readNext();
                    if (token == QXmlStreamReader::StartDocument)
                        continue;
                    if (token == QXmlStreamReader::StartElement) {
                        if (xmlStreamReader.name() == "t") {
                            qDebug() << xmlStreamReader.readElementText();
                        }
                    }
                }

                xmlFile->close();
                QMessageBox::information(this, "Успешно", "Вопросы импортированы");
            }
        }
    }
    else {
        QMessageBox::information(this, "Отказ", "Заполнены не все поля");
    }
}
