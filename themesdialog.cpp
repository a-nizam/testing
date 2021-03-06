#include "themesdialog.h"
#include "ui_themesdialog.h"

ThemesDialog::ThemesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThemesDialog)
{

    ui->setupUi(this);
}

ThemesDialog::~ThemesDialog() {
    delete ui;
}

void ThemesDialog::showEvent(QShowEvent *event) {
    QDialog::showEvent(event);

    // create new model instance for themes view
    if (modelTheme = new ThemesModel(this, *(DBConnection::Instance().db))) {
        // set filter to show only selected ticket type themes
        modelTheme->setFilter(tr("thm_ttype=%1").arg(testId));

        ui->tableViewThemes->setModel(modelTheme);

        // hide id and ticket type columns
        ui->tableViewThemes->hideColumn(ThemesModel::columnName::id);
        ui->tableViewThemes->hideColumn(ThemesModel::columnName::ticket_type);

        // set name column width
        ui->tableViewThemes->setColumnWidth(ThemesModel::columnName::name, 278);

        // set first theme id
        const QModelIndex index = modelTheme->index(0, ThemesModel::columnName::id);
        themeId = modelTheme->data(index).toInt();
    }

    // create new model instance for questions view
    if (modelQuestons = new QuestionsModel(this, *(DBConnection::Instance().db))) {
        // set filter to show only selected theme questions
        modelQuestons->setFilter(tr("question.q_theme=%1 AND relTblAl_3.qtype_name='Простой'").arg(themeId));
        modelQuestons->select();

        ui->tableViewQuestions->setModel(modelQuestons);
        ui->tableViewQuestions->setItemDelegate(new QuestionsDelegate(testId, ui->tableViewQuestions));

        // hide id and ticket type columns
        ui->tableViewQuestions->hideColumn(QuestionsModel::columnName::id);
        ui->tableViewQuestions->hideColumn(QuestionsModel::columnName::theme);
        ui->tableViewQuestions->setColumnWidth(QuestionsModel::columnName::content, 500);

        // set first question id
        const QModelIndex index = modelQuestons->index(0, QuestionsModel::columnName::id);
        quesitonId = modelTheme->data(index).toInt();
    }

    // create new model instance for answer view
    if (modelAnswer = new AnswersModel(this, *(DBConnection::Instance().db))) {
        // set filter to show only selected theme questions
        modelAnswer->setFilter(tr("ans_question=%1").arg(quesitonId));
        modelAnswer->select();

        ui->tableViewAnswers->setModel(modelAnswer);

        // hide id and ticket type columns
        ui->tableViewAnswers->hideColumn(AnswersModel::columnName::id);
        ui->tableViewAnswers->hideColumn(AnswersModel::columnName::question);
    }
}

void ThemesDialog::closeEvent(QCloseEvent *event) {
    QDialog::closeEvent(event);

    // clear model theme to prevent memory leak
    delete modelTheme;
}

void ThemesDialog::setTestId (int _testId) {
    testId = _testId;
}

void ThemesDialog::on_pushButtonAdd_clicked() {
    // get focused treeView and its model
    QTableView *p_tableView = static_cast<QTableView *>(QApplication::focusWidget());
    QSqlRelationalTableModel *p_tableModel = static_cast<QSqlRelationalTableModel *>(p_tableView->model());

    // insert and initialize new row
    p_tableModel->insertRow(p_tableModel->rowCount());
    if (QApplication::focusWidget()->objectName() == "tableViewThemes") {
        const QModelIndex index = p_tableModel->index(p_tableModel->rowCount() - 1, 2);
        p_tableModel->setData(index, testId);
    }
    else {
        if (QApplication::focusWidget()->objectName() == "tableViewQuestions") {
            const QModelIndex index = p_tableModel->index(p_tableModel->rowCount() - 1, 2);
            p_tableModel->setData(index, themeId);
        }
        else {
            if (QApplication::focusWidget()->objectName() == "tableViewAnswers") {
                const QModelIndex index = p_tableModel->index(p_tableModel->rowCount() - 1, 2);
                p_tableModel->setData(index, quesitonId);
            }
        }
    }
}

void ThemesDialog::on_pushButtonRemove_clicked() {
    // get focused treeView and its model
    QTableView *p_tableView = static_cast<QTableView *>(QApplication::focusWidget());
    QSqlRelationalTableModel *p_tableModel = static_cast<QSqlRelationalTableModel *>(p_tableView->model());

    // get selected rows and delete them
    QModelIndexList selectedList = p_tableView->selectionModel()->selectedIndexes();
    for (QModelIndexList::const_iterator i = selectedList.constEnd() - 1; i >= selectedList.constBegin(); --i) {
        p_tableModel->removeRow(i->row());
    }
}

void ThemesDialog::on_pushButtonSave_clicked() {
    // get focused treeView and its model
    QTableView *p_tableView = static_cast<QTableView *>(QApplication::focusWidget());
    QSqlRelationalTableModel *p_tableModel = static_cast<QSqlRelationalTableModel *>(p_tableView->model());

    // save all changes
    p_tableModel->submitAll();
}

void ThemesDialog::on_tableViewThemes_clicked(const QModelIndex &index) {
    const QModelIndex idIndex = modelTheme->index(index.row(), ThemesModel::columnName::id);
    themeId = modelTheme->data(idIndex).toInt();
    modelQuestons->setFilter(tr("q_theme=%1").arg(themeId));
}

void ThemesDialog::on_tableViewQuestions_clicked(const QModelIndex &index) {
    const QModelIndex idIndex = modelQuestons->index(index.row(), QuestionsModel::columnName::id);
    quesitonId = modelQuestons->data(idIndex).toInt();
    modelAnswer->setFilter(tr("ans_question=%1").arg(quesitonId));
}
