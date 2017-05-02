#include "testmodel.h"

TestModel::TestModel(QObject *parent, QSqlDatabase db) : QSqlTableModel(parent, db) {
    setTable("test");
    setEditStrategy(OnRowChange);
    select();
    setHeaderData(0, Qt::Horizontal, tr("Id"));
    setHeaderData(1, Qt::Horizontal, tr("Предмет"));
    setHeaderData(2, Qt::Horizontal, tr("Дата"));
}
