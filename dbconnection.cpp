#include "dbconnection.h"

DBConnection::DBConnection() { }

DBConnection::~DBConnection() { }

int DBConnection::connect(QString dbHost, QString dbName, QString userName, QString userPass) {
    db = new QSqlDatabase();
    *db = QSqlDatabase::addDatabase("QPSQL", "postgres");
    db->setHostName(dbHost);
    db->setDatabaseName(dbName);
    db->setUserName(userName);
    db->setPassword(userPass);
    return (db->open());
}

void DBConnection::disconnect() {
    db->close();
    delete db;
    QSqlDatabase::removeDatabase("postgres");
}

int DBConnection::sendQuery(QString _sQuery, QSqlQuery *&_queryResult) {
    QSqlQuery *query = new QSqlQuery(*db);
    query->exec(_sQuery);
    if (db->lastError().isValid()){
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setText(db->lastError().text());
        msgBox->show();
        return 0;
    }
    else {
        _queryResult = query;
        return 1;
    }
}

int DBConnection::getInfo() {
    QSqlQuery *query = new QSqlQuery(*db);
    query->exec("SELECT * FROM student");

    if (db->lastError().isValid()){
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setText(db->lastError().text());
        msgBox->show();
    }

    while (query->next()) {
        QString name = query->value(1).toString();
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setText(name);
        msgBox->show();
    }
    return 0;
}
