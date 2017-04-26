#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // connecting to postgresql
    dbConnection = new DBConnection();
    if(!dbConnection->connect("localhost", "testing", "postgres", "123456")) {
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setText("Не удалось установить соединение с базой данных");
        msgBox->show();
    }

    // creating and setting model of tests list
    modelTests = new TestModel();
    ui->listView->setModel(modelTests);

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
    dbConnection->disconnect();
    delete ui;
}

//void unzip_doc_content() {
//    QString path("C:\\Users\\Nizam\\Desktop\\tmp");
//    QZipReader *zip_reader = new QZipReader(path + QDir::separator() + "tz.docx");
//    if (zip_reader->exists()) {
//        QFile file(path + QDir::separator() + "document.xml");
//        if(file.open(QFile::WriteOnly)) {
//            foreach (QZipReader::FileInfo info, zip_reader->fileInfoList()) {
//                if (info.filePath == "word/document.xml") {
//                    file.write(zip_reader->fileData(info.filePath), zip_reader->fileData(info.filePath).size());
//                    file.close();
//                    break;
//                }
//            }
//        }
//    }
//    delete zip_reader;
//}

void MainWindow::on_action_13_triggered()
{
    TestWindow *tw = new TestWindow();
    tw->show();
}
