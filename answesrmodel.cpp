#include "answesrmodel.h"

AnswesrModel::AnswesrModel(QObject *parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase()) : QSqlRelationalTableModel(parent, db) {
    setTable("answer");
    setEditStrategy(OnManualSubmit);
    setHeaderData(columnName::content, Qt::Horizontal, tr("Ответ"));
    setHeaderData(columnName::isCorrect, Qt::Horizontal, tr("Правильный"));
    select();
}
