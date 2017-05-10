#ifndef ANSWESRMODEL_H
#define ANSWESRMODEL_H

#include <QObject>
#include <QSqlRelationalTableModel>

class AnswesrModel : public QSqlRelationalTableModel
{
public:
    enum columnName {
        id, content, question, isCorrect
    };
    explicit AnswesrModel(QObject *parent, QSqlDatabase db);
};

#endif // ANSWESRMODEL_H
