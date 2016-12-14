#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(button_clicked_trigger()));
    connect(this, &MainWindow::buttonClicked, this, &MainWindow::button_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button_clicked(int buttonID) {
    QMessageBox *msgBox = new QMessageBox();
    msgBox->setText(QString("%1").arg(buttonID));
    msgBox->show();
}

void MainWindow::button_clicked_trigger() {
    emit buttonClicked(555);
}
