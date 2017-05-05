#ifndef THEMESDIALOG_H
#define THEMESDIALOG_H

#include <QDialog>

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
};

#endif // THEMESDIALOG_H
