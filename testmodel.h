#ifndef TESTMODEL_H
#define TESTMODEL_H

#include <QSqlTableModel>

class TestModel : public QSqlTableModel
{
public:
    explicit TestModel(QObject *parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase());
};

#endif // TESTMODEL_H
