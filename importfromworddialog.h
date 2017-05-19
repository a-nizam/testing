#ifndef IMPORTFROMWORDDIALOG_H
#define IMPORTFROMWORDDIALOG_H

#include <QDebug>
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QXmlStreamReader>
#include <QStringListModel>

namespace Ui {
class ImportFromWordDialog;
}

class ImportFromWordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ImportFromWordDialog(QWidget *parent = 0);
    ~ImportFromWordDialog();

private slots:
    void on_pushButtonFileBrowse_clicked();
    void on_pushButtonImport_clicked();

private:
    Ui::ImportFromWordDialog *ui;
    void showEvent(QShowEvent *);
    QStringListModel *testsModel;
    QStringListModel *themesModel;

private:
    int unzipDocumentXml(QString path);
};

#endif // IMPORTFROMWORDDIALOG_H
