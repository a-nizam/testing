#ifndef THEMESDIALOG_H
#define THEMESDIALOG_H

#include <QDialog>
#include "dbconnection.h"
#include "themesmodel.h"
#include "questionsmodel.h"

namespace Ui {
class ThemesDialog;
}

class ThemesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ThemesDialog(QWidget *parent = 0);
    ~ThemesDialog();

private:
    Ui::ThemesDialog *ui;
    int testId;
    int themeId;
    void showEvent(QShowEvent *);
    void closeEvent(QCloseEvent *);
    ThemesModel *modelTheme;
    QuestionsModel *questionsModel;
public:
    void setTestId (int _testId);
private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonRemove_clicked();
    void on_pushButtonSave_clicked();
};

#endif // THEMESDIALOG_H
