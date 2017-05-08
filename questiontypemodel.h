#ifndef QUESTIONTYPEMODEL_H
#define QUESTIONTYPEMODEL_H

#include <QObject>
#include <QSqlTableModel>

class QuestionTypeModel : public QSqlTableModel
{
public:
    enum columnName {
        id, name, cost
    };

    explicit QuestionTypeModel(QObject *parent, QSqlDatabase db);
};

#endif // QUESTIONTYPEMODEL_H
