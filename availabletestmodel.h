#ifndef AVAILABLETESTMODEL_H
#define AVAILABLETESTMODEL_H

#include <QObject>
#include <QSqlRelationalTableModel>
#include "dbconnection.h"

class AvailableTestModel : public QSqlRelationalTableModel
{
public:
    enum columnName {
        id, name, subject
    };

    explicit AvailableTestModel(QObject *parent, QSqlDatabase db);
    virtual Qt::ItemFlags flags(const QModelIndex& index) const override;
};

#endif // AVAILABLETESTMODEL_H
