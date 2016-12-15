#include "dbconnection.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(push_button_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::push_button_clicked() {
    DBConnection *dbConnection = new DBConnection();
    if(dbConnection->connect("localhost", "postgres", "postgres", "123456")) {
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setText("Соединение установлено");
        msgBox->show();
        delete msgBox;
        dbConnection->disconnect();
    }
}
