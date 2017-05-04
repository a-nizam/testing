#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlField>
#include <QSqlIndex>
#include <QSqlRecord>
#include <QMessageBox>


class DBConnection : public QObject
{
    Q_OBJECT
public:
    static DBConnection &Instance() {
        static DBConnection s;
        return s;
    }

private:
    DBConnection();
    ~DBConnection();
    DBConnection(DBConnection const&) = delete;
    DBConnection& operator= (DBConnection const&) = delete;
public:
    QString dbHost;
    QString dbName;
    QString userName;
    QString userPass;
    QSqlDatabase *db;

public:
    int connect(QString dbHost, QString dbName, QString userName, QString userPass);
    void disconnect();
    int getInfo();
    int sendQuery(QString _sQuery, QSqlQuery *&_queryResult);

signals:

public slots:
};

#endif // DBCONNECTION_H
