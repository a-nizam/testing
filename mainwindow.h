#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QStringListModel>
#include "dbconnection.h"
#include "testmodel.h"
#include "testwindow.h"

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
    void on_action_13_triggered();

private:
    Ui::MainWindow *ui;
    DBConnection *dbConnection;
    TestModel *modelTests;

private:

};

#endif // MAINWINDOW_H
