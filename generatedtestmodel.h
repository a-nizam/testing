#ifndef TESTMODEL_H
#define TESTMODEL_H

#include <QObject>
#include <QSqlRelationalTableModel>

class GeneratedTestModel : public QSqlRelationalTableModel
{
public:
    enum columnName {
        id, ticket_type, date
    };

    explicit GeneratedTestModel(QObject *parent, QSqlDatabase db);
    virtual Qt::ItemFlags flags(const QModelIndex& index) const override;
};

#endif // TESTMODEL_H
