#include "questiontypedialog.h"
#include "ui_questiontypedialog.h"

QuestionTypeDialog::QuestionTypeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuestionTypeDialog)
{
    ui->setupUi(this);
}

QuestionTypeDialog::~QuestionTypeDialog()
{
    delete ui;
}

void QuestionTypeDialog::on_pushButtonAdd_clicked()
{
    questionTypeModel->insertRow(questionTypeModel->rowCount());
}

void QuestionTypeDialog::on_pushButtonSave_clicked() {
    questionTypeModel->submitAll();
}

void QuestionTypeDialog::on_pushButtonDelete_clicked() {
    QModelIndexList selectedList = ui->tableView->selectionModel()->selectedIndexes();
    for (QModelIndexList::const_iterator i = selectedList.constEnd() - 1; i >= selectedList.constBegin(); --i) {
        questionTypeModel->removeRow(i->row());
    }
}

void QuestionTypeDialog::on_pushButtonReset_clicked()
{
    questionTypeModel->select();
}

void QuestionTypeDialog::showEvent(QShowEvent *event) {
    QDialog::showEvent(event);

    if (questionTypeModel = new QuestionTypeModel(this, *(DBConnection::Instance().db))) {
        ui->tableView->setModel(questionTypeModel);
        ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
        ui->tableView->hideColumn(QuestionTypeModel::columnName::id);
        ui->tableView->setColumnWidth(QuestionTypeModel::columnName::name, 150);
        ui->tableView->setColumnWidth(QuestionTypeModel::columnName::ticket_type, 193);
        ui->tableView->setColumnWidth(QuestionTypeModel::columnName::cost, 80);
    }
}
