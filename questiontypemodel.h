#ifndef QUESTIONTYPEMODEL_H
#define QUESTIONTYPEMODEL_H

#include <QObject>
#include <QSqlTableModel>

class QuestionTypeModel : public QSqlTableModel
{
public:
    explicit QuestionTypeModel(QObject *parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase());
};

#endif // QUESTIONTYPEMODEL_H
