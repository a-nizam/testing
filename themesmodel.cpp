#include "themesmodel.h"

ThemesModel::ThemesModel(QObject *parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase()) : QSqlRelationalTableModel(parent, db) {
    setTable("theme");
    setEditStrategy(OnManualSubmit);
    setHeaderData(columnName::name, Qt::Horizontal, tr("Название"));
    select();
}
