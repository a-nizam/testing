#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void buttonClicked(int buttonID);

private slots:
    void button_clicked(int buttonID);
    void button_clicked_trigger();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
