#ifndef TESTMODEL_H
#define TESTMODEL_H

#include <QObject>
#include <QSqlRelationalTableModel>

class GeneratedTestModel : public QSqlRelationalTableModel
{
public:
    explicit GeneratedTestModel(QObject *parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase());
    virtual Qt::ItemFlags flags(const QModelIndex& index) const override;
};

#endif // TESTMODEL_H
