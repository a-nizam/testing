#include "dbconnection.h"

DBConnection::DBConnection(QObject *parent) : QObject(parent)
{

}


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

int DBConnection::getInfo() {
    QSqlQuery *query = new QSqlQuery(*db);
    query->exec("sdgsdgsfg");
    if (db->lastError().isValid()){
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setText(db->lastError().text());
        msgBox->show();
    }


    while (query->next()) {
        QString name = query->value(0).toString();
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setText(name);
        msgBox->show();
    }
    return 0;
}
