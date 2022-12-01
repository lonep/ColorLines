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
           if (j == 1)
           {
               GameCell *cell = new GameCell(Colors::yellow);
               row.push_back(cell);
           }
           else
           {
               GameCell *cell = new GameCell();
               row.push_back(cell);
           }
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

void GameDesk::clearData(const QModelIndex &index, int role)
{
    if (index.isValid())
        setData(index, Colors::none);
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
    int counter = 0;
    int currentColor = 0;

    QVector<QModelIndex> result;

    for (int i = 0; i < DESK_SIZE; i++) //Find win row by horizonal
    {
        for (int j = 0; j < DESK_SIZE; j++)
        {
            if (gameDesk[i][j]->getBall() == Colors::none)
            {
                currentColor = Colors::none;
                counter = 0;
                continue;
            }

            if (!(currentColor == gameDesk[i][j]->getBall()))
            {
                currentColor = gameDesk[i][j]->getBall();
                counter = 1;
            }
            else counter++;

            if (counter == WIN_NUMBER_IN_ROW)
            {
                for (int k = j; k >= 0; k--)
                    result.push_back(index(i, k));
                counter = 0;
            }
        }
    }

    for (int j = 0; j < DESK_SIZE; j++) //Find win row by vertical
    {
        for (int i = 0; i < DESK_SIZE; i++)
        {
            if (gameDesk[i][j]->getBall() == Colors::none)
            {

                currentColor = Colors::none;
                counter = 0;
                continue;
            }

            if (!(currentColor == gameDesk[i][j]->getBall()))
            {
                currentColor = gameDesk[i][j]->getBall();
                counter = 1;
            }
            else counter++;

            if (counter == WIN_NUMBER_IN_ROW)
            {
                for (int k = i; k >= 0; k--)
                    result.push_back(index(k, j));
                counter = 0;
            }
        }
    }



    return result;
}

void GameDesk::clearCells(const QVector<QModelIndex> &cells)
{
    foreach (auto it, cells)
    {
        clearData(it);
    }
}

int GameDesk::makeSomething()
{
    return 1;
}
