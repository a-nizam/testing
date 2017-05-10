#ifndef THEMESDIALOG_H
#define THEMESDIALOG_H

#include <QDialog>
#include <QSqlRelationalDelegate>
#include "dbconnection.h"
#include "themesmodel.h"
#include "questionsmodel.h"
#include "answesrmodel.h"

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
    int quesitonId;
    void showEvent(QShowEvent *);
    void closeEvent(QCloseEvent *);
    ThemesModel *modelTheme;
    QuestionsModel *modelQuestons;
    AnswesrModel *modelAnswer;
public:
    void setTestId (int _testId);
private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonRemove_clicked();
    void on_pushButtonSave_clicked();
    void on_tableViewThemes_clicked(const QModelIndex &index);
    void on_tableViewQuestions_clicked(const QModelIndex &index);
};

#endif // THEMESDIALOG_H
