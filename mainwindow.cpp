#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    questionTypeDialog(new QuestionTypeDialog(this)),
    themeDialog(new ThemesDialog(this)),
    importFromWordDialog(new ImportFromWordDialog(this))
{
    ui->setupUi(this);

    // connect to postgresql
    if(!DBConnection::Instance().connect("localhost", "testing", "postgres", "123456")) {
        QMessageBox msgBox;
        msgBox.setText(tr("Не удалось установить соединение с базой данных (%1)").arg(DBConnection::Instance().db->lastError().text()));
        msgBox.exec();
    }

    // set models of generated and available tests table view
    setGeneratedTestModel();
    setAvailableTestModel();

//    sending request template
//    QSqlQuery *qQuery;
//    if (dbConnection->sendQuery("SELECT * FROM student", qQuery)) {
//        while (qQuery->next()) {
//            QString name = qQuery->value(1).toString();
//            QMessageBox *msgBox = new QMessageBox();
//            msgBox->setText(name);
//            msgBox->show();
//        }
//    }
}

MainWindow::~MainWindow()
{
    delete  questionTypeDialog;
    delete themeDialog;
    delete importFromWordDialog;
    DBConnection::Instance().disconnect();
    delete ui;
}

// create and set model of tests list
int MainWindow::setGeneratedTestModel() {
    if (modelGeneratedTests = new GeneratedTestModel(this, *(DBConnection::Instance().db))) {
        ui->tableViewTests->setModel(modelGeneratedTests);
        ui->tableViewTests->setItemDelegate(new QSqlRelationalDelegate(ui->tableViewTests));
        ui->tableViewTests->hideColumn(GeneratedTestModel::columnName::id);
        return 1;
    }
    else {
        return 0;
    }
}

// create and set model of available tests list
int MainWindow::setAvailableTestModel() {
    if (modelAvailableTests = new AvailableTestModel(this, *(DBConnection::Instance().db))) {
        ui->tableViewAvailable->setModel(modelAvailableTests);
        ui->tableViewAvailable->setItemDelegate(new QSqlRelationalDelegate(ui->tableViewAvailable));
        ui->tableViewAvailable->hideColumn(AvailableTestModel::columnName::id);
        return 1;
    }
    else {
        return 0;
    }
}

void MainWindow::on_action_6_triggered() {
    questionTypeDialog->show();
}

void MainWindow::on_tableViewAvailable_doubleClicked(const QModelIndex &index) {
    // send test id to theme dialog
    themeDialog->setTestId(modelAvailableTests->index(index.row(), AvailableTestModel::columnName::id).data().toInt());

    themeDialog->show();
}

void MainWindow::on_action_7_triggered() {
    QMessageBox::critical(this, "", QApplication::focusWidget()->objectName());
}

void MainWindow::on_action_3_triggered() {
    importFromWordDialog->show();
}
