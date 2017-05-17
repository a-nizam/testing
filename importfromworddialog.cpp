#include "importfromworddialog.h"
#include "ui_importfromworddialog.h"
#include "qzip.cpp"

ImportFromWordDialog::ImportFromWordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportFromWordDialog)
{
    ui->setupUi(this);
}

ImportFromWordDialog::~ImportFromWordDialog()
{
    delete ui;
}

void ImportFromWordDialog::on_pushButtonFileBrowse_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this);
    ui->lineEditFileBrowse->setText(fileName);
    ui->lineEditFileBrowse->setCursorPosition(0);
}

void ImportFromWordDialog::unzipDocumentXml(QString _path) {
    QZipReader *zip_reader = new QZipReader(_path);
    if (zip_reader->exists()) {
        QFile file("document.xml");
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

void ImportFromWordDialog::on_pushButtonImport_clicked() {
    unzipDocumentXml(ui->lineEditFileBrowse->text());
}
