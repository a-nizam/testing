#ifndef IMPORTFROMWORDDIALOG_H
#define IMPORTFROMWORDDIALOG_H

#include <QDebug>
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QXmlStreamReader>
#include <QStringList>
#include "dbconnection.h"

#define QUESTION_SYMBOL "?"
#define AND_OF_LINE_SYMBOL "!"
#define QUESTION_COST_POSITION 1
#define NO_VARIANT_SYMBOL_POSITION 2
#define SPECIAL_SYMBOL_MAX_COUNT 3
#define SPECIAL_SYMBOL_COUNT_WITH_VARIANTS 2

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

    void on_comboBoxTests_activated(int index);

private:
    Ui::ImportFromWordDialog *ui;
    void showEvent(QShowEvent *);
    int _errno;
    QString _errorMsg;
    QStringList testsList;
    QList<QString> themesList;
    QList<int> testIdList, themeIdList;

private:
    int unzipDocumentXml(QString path);
    int getQuestionTypeId(int _testId, int _cost) const;
};

#endif // IMPORTFROMWORDDIALOG_H
