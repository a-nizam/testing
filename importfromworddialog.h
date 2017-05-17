#ifndef IMPORTFROMWORDDIALOG_H
#define IMPORTFROMWORDDIALOG_H

#include <QDialog>
#include <QFileDialog>

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

private:
    void unzipDocumentXml(QString path);
};

#endif // IMPORTFROMWORDDIALOG_H
