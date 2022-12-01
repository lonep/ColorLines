#include "gamedesk.h"
#include "Colors.h"

GameDesk::GameDesk(QObject *parent)
    : QAbstractItemModel(parent)
{
    for (int i = 0; i < DESK_SIZE; i++)
    {
        QVector <GameCell*> row;

        for (int j = 0; j < DESK_SIZE; j++)
        {
           GameCell *cell = new GameCell();
           row.push_back(cell);
        }

        gameDesk.push_back(row);
    }
}

GameDesk::~GameDesk()
{
    foreach (auto it, gameDesk) {
        it.clear();
    }
}


QModelIndex GameDesk::index(int row, int column, const QModelIndex &parent) const
{
    return createIndex(row, column);
}

QModelIndex GameDesk::parent(const QModelIndex &child) const
{

}

int GameDesk::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    return gameDesk.front().size();
}

int GameDesk::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    return gameDesk.size();
}

QVariant GameDesk::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= rowCount() || index.column() >= columnCount())
            return QVariant();

        if (role == Qt::DisplayRole)
            return gameDesk[index.row()][index.column()]->getBall();
        else
            return QVariant();
}

bool GameDesk::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.row() >= rowCount() || index.column() >= columnCount()) {

        gameDesk[index.row()][index.column()]->setBall(value.toInt());

        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}

Qt::ItemFlags GameDesk::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable; // FIXME: Implement me!
}

QVector<QModelIndex> GameDesk::getEmptyCells()
{
    QVector<QModelIndex> result;

    for (int i = 0; i < DESK_SIZE; i++)
    {
        for (int j = 0; j < DESK_SIZE; j++)
        {
            if (gameDesk[i][j]->getBall() == Colors::none)
                result.push_back(index(i, j));
        }
    }
    return result;
}

QVector<QModelIndex> GameDesk::findWinRow()
{

}

int GameDesk::makeSomething()
{
    return 1;
}
