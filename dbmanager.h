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

    template <class T>
    void saveData(const T data);
    void saveData(const QModelIndex &index);
    void saveData(const QVector<QModelIndex> &indexes);

    QVector<GameCell*> getData();

private:
    QSqlDatabase db;

};

#endif // DBMANAGER_H
