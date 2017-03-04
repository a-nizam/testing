#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dbConnection = new DBConnection();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    dbConnection->disconnect();
}

void MainWindow::on_pushButton_3_clicked()
{
    dbConnection->getInfo();
}

void MainWindow::on_pushButton_clicked()
{
    if(dbConnection->connect("localhost", "postgres", "postgres", "123456")) {
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setText("Соединение установлено");
        msgBox->show();
    }
    else {
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setText("Не удалось установить соединение");
        msgBox->show();
    }
}
