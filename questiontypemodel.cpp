#include "questiontypemodel.h"

QuestionTypeModel::QuestionTypeModel(QObject *parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase()) :
    QSqlRelationalTableModel(parent, db) {

    setTable("question_type");
    setEditStrategy(OnManualSubmit);
    setRelation(columnName::ticket_type, QSqlRelation("ticket_type", "ttype_id", "ttype_name"));
    setHeaderData(columnName::name, Qt::Horizontal, tr("Название"));
    setHeaderData(columnName::ticket_type, Qt::Horizontal, tr("Тест"));
    setHeaderData(columnName::cost, Qt::Horizontal, tr("Стоимость"));
    select();
}
