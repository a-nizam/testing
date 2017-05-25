#ifndef QUESTIONSMODEL_H
#define QUESTIONSMODEL_H

#include <QObject>
#include <QSqlRelationalTableModel>

class QuestionsModel : public QSqlRelationalTableModel
{
public:
    enum columnName {
        id, content, theme, type, no_variants, unit
    };

    explicit QuestionsModel(QObject *parent, QSqlDatabase db);
};

#endif // QUESTIONSMODEL_H
