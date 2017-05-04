#include "questiontypedialog.h"
#include "ui_questiontypewindow.h"

QuestionTypeDialog::QuestionTypeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuestionTypeDialog)
{
    ui->setupUi(this);

    DBConnection &dbConnection = DBConnection::Instance();

    questionTypeModel = new QuestionTypeModel(Q_NULLPTR, *(dbConnection.db));
    ui->tableView->setModel(questionTypeModel);
    ui->tableView->hideColumn(0);
    ui->tableView->setColumnWidth(1, 300);
}

QuestionTypeDialog::~QuestionTypeDialog()
{
    delete ui;
}

void QuestionTypeDialog::on_pushButtonAdd_clicked()
{
    questionTypeModel->insertRow(questionTypeModel->rowCount());
}

void QuestionTypeDialog::on_pushButtonSave_clicked()
{
    questionTypeModel->submitAll();
}

void QuestionTypeDialog::on_pushButtonDelete_clicked()
{
    QModelIndexList selectedList = ui->tableView->selectionModel()->selectedIndexes();
    for (QModelIndexList::const_iterator i = selectedList.constEnd() - 1; i >= selectedList.constBegin(); --i) {
        questionTypeModel->removeRow(i->row());
    }
}

void QuestionTypeDialog::on_pushButtonReset_clicked()
{
    questionTypeModel->select();
}
