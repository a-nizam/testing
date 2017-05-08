#include "availabletestmodel.h"

AvailableTestModel::AvailableTestModel(QObject *parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase()) : QSqlRelationalTableModel(parent, db) {
    setTable("ticket_type");
    setEditStrategy(OnManualSubmit);
    setRelation(2, QSqlRelation("subject", "sub_id", "sub_name"));
    setHeaderData(columnName::name, Qt::Horizontal, tr("Название"));
    setHeaderData(columnName::subject, Qt::Horizontal, tr("Предмет"));
    select();
}

Qt::ItemFlags AvailableTestModel::flags(const QModelIndex& index) const {
    Qt::ItemFlags result = QSqlRelationalTableModel::flags(index);
    if (index.column() == columnName::name || index.column() == columnName::subject) {
        result &= ~Qt::ItemIsEditable;
    }
    return result;
}
