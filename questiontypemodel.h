#ifndef QUESTIONTYPEMODEL_H
#define QUESTIONTYPEMODEL_H

#include <QObject>
#include <QSqlRelationalTableModel>

class QuestionTypeModel : public QSqlRelationalTableModel
{
public:
    enum columnName {
        id, name, ticket_type, cost
    };

    explicit QuestionTypeModel(QObject *parent, QSqlDatabase db);
};

#endif // QUESTIONTYPEMODEL_H
