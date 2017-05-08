#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QStringListModel>
#include <QSqlRelationalDelegate>
#include "dbconnection.h"
#include "generatedtestmodel.h"
#include "availabletestmodel.h"
#include "questiontypedialog.h"
#include "themesdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_action_6_triggered();

    void on_tableViewAvailable_doubleClicked(const QModelIndex &index);

    void on_action_7_triggered();

private:
    Ui::MainWindow *ui;
    GeneratedTestModel *modelGeneratedTests;
    AvailableTestModel *modelAvailableTests;
    QuestionTypeDialog *questionTypeDialog;
    ThemesDialog * themeDialog;

private:
    inline int setGeneratedTestModel();
    inline int setAvailableTestModel();
};

#endif // MAINWINDOW_H
