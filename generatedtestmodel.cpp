#include "generatedtestmodel.h"

GeneratedTestModel::GeneratedTestModel(QObject *parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase()) : QSqlRelationalTableModel(parent, db) {
    setTable("test");
    setEditStrategy(OnManualSubmit);
    setRelation(1, QSqlRelation("ticket_type", "ttype_id", "ttype_name"));
    setHeaderData(columnName::ticket_type, Qt::Horizontal, tr("Тест"));
    setHeaderData(columnName::date, Qt::Horizontal, tr("Дата"));
    select();
}

Qt::ItemFlags GeneratedTestModel::flags(const QModelIndex& index) const {
    Qt::ItemFlags result = QSqlRelationalTableModel::flags(index);
    if (index.column() == columnName::ticket_type || index.column() == columnName::date) {
        result &= ~Qt::ItemIsEditable;
    }
    return result;
}
