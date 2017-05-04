#include "availabletestmodel.h"

AvailableTestModel::AvailableTestModel(QObject *parent, QSqlDatabase db) : QSqlRelationalTableModel(parent, db) {
    setTable("ticket_type");
    setEditStrategy(OnManualSubmit);
    setRelation(1, QSqlRelation("subject", "sub_id", "sub_name"));
    setHeaderData(1, Qt::Horizontal, tr("Предмет"));
    select();
}

Qt::ItemFlags AvailableTestModel::flags(const QModelIndex& index) const {
    Qt::ItemFlags result = QSqlRelationalTableModel::flags(index);
    if (index.column() == 1) {
        result &= ~Qt::ItemIsEditable;
    }
    return result;
}
