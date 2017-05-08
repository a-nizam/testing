#include "questiontypemodel.h"

QuestionTypeModel::QuestionTypeModel(QObject *parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase()) : QSqlTableModel(parent, db) {
    setTable("question_type");
    setEditStrategy(OnManualSubmit);
    setHeaderData(columnName::name, Qt::Horizontal, tr("Название"));
    setHeaderData(columnName::cost, Qt::Horizontal, tr("Стоимость"));
    select();
}
