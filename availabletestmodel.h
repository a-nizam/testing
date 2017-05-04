#ifndef AVAILABLETESTMODEL_H
#define AVAILABLETESTMODEL_H

#include <QObject>
#include <QSqlRelationalTableModel>
#include "dbconnection.h"

class AvailableTestModel : public QSqlRelationalTableModel
{
public:
    explicit AvailableTestModel(QObject *parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase());
    virtual Qt::ItemFlags flags(const QModelIndex& index) const override;
};

#endif // AVAILABLETESTMODEL_H
