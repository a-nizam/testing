#include "generatedtestmodel.h"

GeneratedTestModel::GeneratedTestModel(QObject *parent, QSqlDatabase db) : QSqlRelationalTableModel(parent, db) {
    setTable("test");
    setEditStrategy(OnManualSubmit);
    setRelation(1, QSqlRelation("subject", "sub_id", "sub_name"));
    setHeaderData(1, Qt::Horizontal, tr("Предмет"));
    setHeaderData(2, Qt::Horizontal, tr("Дата"));
    select();
}

Qt::ItemFlags GeneratedTestModel::flags(const QModelIndex& index) const {
    Qt::ItemFlags result = QSqlRelationalTableModel::flags(index);
    if (index.column() == 1 || index.column() == 2) {
        result &= ~Qt::ItemIsEditable;
    }
    return result;
}
