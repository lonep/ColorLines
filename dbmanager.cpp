#include "dbmanager.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QCoreApplication>

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



    query.exec(QString("INSERT INTO %1 VALUES (%2, %3, %4)")
               .arg("gameDesk")
               .arg(index.row())
               .arg(index.column())
               .arg(index.model()->data(index).toInt()));

//    qDebug() << index.data();

}

void DBmanager::saveData(const QVector<QModelIndex> &indexes)
{

    QSqlQuery deleteQuery;
    deleteQuery.exec(QString("DELETE FROM %1").arg("gameDesk"));
    qDebug() << deleteQuery.lastError().text();

    for (int i = 0; i < indexes.size(); i++)
    {
        saveData(indexes[i]);
    }
}

QVector<GameCell *> DBmanager::getData()
{
    QSqlQuery query;
    QVector<GameCell*> result;

    query.exec(QString("SELECT * FROM %1").arg("gameDesk"));

    while (query.next())
        result.push_back(new GameCell(query.value(2).toInt()));

    return result;

}

template<class T>
void DBmanager::saveData(const T data)
{

}
