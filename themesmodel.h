#ifndef THEMEMODEL_H
#define THEMEMODEL_H

#include <QObject>
#include <QSqlRelationalTableModel>

class ThemesModel : public QSqlRelationalTableModel
{
public:
    enum columnName {
        id, name, ticket_type
    };

    explicit ThemesModel(QObject *parent, QSqlDatabase db);
};

#endif // THEMEMODEL_H
