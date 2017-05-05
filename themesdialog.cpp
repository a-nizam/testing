#include "themesdialog.h"
#include "ui_themesdialog.h"

ThemesDialog::ThemesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThemesDialog)
{
    ui->setupUi(this);
}

ThemesDialog::~ThemesDialog()
{
    delete ui;
}
