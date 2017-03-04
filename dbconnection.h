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
    explicit DBConnection(QObject *parent = 0);
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

signals:

public slots:
};

#endif // DBCONNECTION_H
