#ifndef QUESTIONTYPEWINDOW_H
#define QUESTIONTYPEWINDOW_H

#include <QDialog>
#include "dbconnection.h"
#include "questiontypemodel.h"

namespace Ui {
class QuestionTypeDialog;
}

class QuestionTypeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QuestionTypeDialog(QWidget *parent = 0);
    ~QuestionTypeDialog();

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonDelete_clicked();

    void on_pushButtonReset_clicked();

private:
    Ui::QuestionTypeDialog *ui;
    QuestionTypeModel *questionTypeModel;
};

#endif // QUESTIONTYPEWINDOW_H
