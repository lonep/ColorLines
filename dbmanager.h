#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QSqlDatabase>
#include <QVector>
#include <QModelIndex>

#include <gamecell.h>

class DBmanager //Using for only SqLite
{
public:
    DBmanager();
    DBmanager(const QString &dbName, const QString &hostName = "", const QString &userName = "", const QString &dbPassword = "");

    void saveData(const QModelIndexList &indexes);

    QList<GameCell*> getData();

private:
    QSqlDatabase db;

    void saveData(const QModelIndex &index);

};

#endif // DBMANAGER_H
