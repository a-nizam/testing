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
    if(dbConnection->connect("localhost", "testing", "postgres", "123456")) {
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

void MainWindow::on_pushButton_4_clicked()
{
    QString path("C:\\Users\\Nizam\\Desktop\\tmp");
    QZipReader *zip_reader = new QZipReader(path + QDir::separator() + "tz.docx");
    if (zip_reader->exists()) {
        QFile file(path + QDir::separator() + "document.xml");
        if(file.open(QFile::WriteOnly)) {
            foreach (QZipReader::FileInfo info, zip_reader->fileInfoList()) {
                if (info.filePath == "word/document.xml") {
                    file.write(zip_reader->fileData(info.filePath), zip_reader->fileData(info.filePath).size());
                    file.close();
                    break;
                }
            }
        }
    }
    delete zip_reader;
}
