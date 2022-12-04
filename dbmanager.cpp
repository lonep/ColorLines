#include "dbmanager.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QCoreApplication>

#define MODEL_ROLE 256

DBmanager::DBmanager()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

DBmanager::DBmanager(const QString &dbName, const QString &hostName, const QString &userName, const QString &dbPassword)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(hostName);
    db.setDatabaseName(QString(QCoreApplication::applicationDirPath() + "/" + dbName));
    db.setUserName(userName);
    db.setPassword(dbPassword);


    db.open();
}

void DBmanager::saveData(const QModelIndex &index)
{
    QSqlQuery query;

    query.exec(QString("INSERT INTO %1 VALUES (%4)")
               .arg("gameDesk")
               .arg(index.row()));

}

void DBmanager::saveData(const QModelIndexList &indexes)
{

    QSqlQuery deleteQuery;
    deleteQuery.exec(QString("DELETE FROM %1").arg("gameDesk")); //Данные не обновляются, а перезаписываются.

    for (int i = 0; i < indexes.size(); i++) 
        saveData(indexes[i]);

}

QList<GameCell *> DBmanager::getData()
{
    QSqlQuery query;
    QVector<GameCell*> result;

    query.exec(QString("SELECT * FROM %1").arg("gameDesk"));

    while (query.next())
        result.push_back(new GameCell(query.value(0).toInt()));

    return result;

}


