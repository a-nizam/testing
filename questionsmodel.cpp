#include "questionsmodel.h"

QuestionsModel::QuestionsModel(QObject *parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase()) : QSqlRelationalTableModel(parent, db) {
    setTable("question");
    setEditStrategy(OnManualSubmit);
    setRelation(columnName::type, QSqlRelation("question_type", "qtype_id", "qtype_name"));
    setHeaderData(columnName::content, Qt::Horizontal, tr("Вопрос"));
    setHeaderData(columnName::type, Qt::Horizontal, tr("Категория"));
    setHeaderData(columnName::no_variants, Qt::Horizontal, tr("Без вариантов"));
    setHeaderData(columnName::unit, Qt::Horizontal, tr("Единица измерения"));
}
