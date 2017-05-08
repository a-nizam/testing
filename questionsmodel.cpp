#include "questionsmodel.h"

QuestionsModel::QuestionsModel(QObject *parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase()) : QSqlRelationalTableModel(parent, db) {
    setTable("theme");
    setEditStrategy(OnManualSubmit);
    setRelation(columnName::type, QSqlRelation("question_type", "qtype_id", "qtype_name"));
    setHeaderData(columnName::content, Qt::Horizontal, tr("Вопрос"));
    setHeaderData(columnName::type, Qt::Horizontal, tr("Категория"));
    select();
}
