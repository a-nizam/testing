#include "questiontypemodel.h"

QuestionTypeModel::QuestionTypeModel(QObject *parent, QSqlDatabase db) : QSqlTableModel(parent, db) {
    setTable("question_type");
    setEditStrategy(OnManualSubmit);
    setHeaderData(1, Qt::Horizontal, tr("Название"));
    setHeaderData(2, Qt::Horizontal, tr("Стоимость"));
    select();
}
