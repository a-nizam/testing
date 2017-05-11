#ifndef ANSWESRMODEL_H
#define ANSWESRMODEL_H

#include <QObject>
#include <QSqlRelationalTableModel>

class AnswersModel : public QSqlRelationalTableModel
{
public:
    enum columnName {
        id, content, question, isCorrect
    };
    explicit AnswersModel(QObject *parent, QSqlDatabase db);
};

#endif // ANSWESRMODEL_H
