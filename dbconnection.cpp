#include "dbconnection.h"

DBConnection::DBConnection(QObject *parent) : QObject(parent)
{

}


int DBConnection::connect(QString dbHost, QString dbName, QString userName, QString userPass) {
    db = QSqlDatabase::addDatabase("QPSQL", "postgres");
    db.setHostName(dbHost);
    db.setDatabaseName(dbName);
    db.setUserName(userName);
    db.setPassword(userPass);
    return (db.open());
}

void DBConnection::disconnect() {
    db.close();
}
