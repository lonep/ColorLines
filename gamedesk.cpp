#include "gamedesk.h"
#include "Colors.h"

GameDesk::GameDesk(QObject *parent)
    : QAbstractItemModel(parent)
{
    for (int i = 0; i < DESK_SIZE * DESK_SIZE; i++)// TODO fix constructor
    {
       if (i >= 0 && i < 9)
           gameDesk.push_back(new GameCell(Colors::green));
               else if(i >= 9 && i < 18) gameDesk.push_back(new GameCell(Colors::yellow));
               else gameDesk.push_back(new GameCell(Colors::none));

    }
}

GameDesk::~GameDesk()
{
    gameDesk.clear();
}


QModelIndex GameDesk::index(int row, int column, const QModelIndex &parent) const
{
    qDebug() << "index Row - " << row << "index column - " << column;
    return createIndex(row, 0, gameDesk[row]);
}

QHash<int, QByteArray> GameDesk::roleNames() const
{
    QHash<int, QByteArray> roles ;
    roles[Roles::BallRole] = "ball";
    roles[Roles::second] = "second";

    return roles;
}

QModelIndex GameDesk::parent(const QModelIndex &child) const
{
//    return QAbstractItemModel::parent(child);
}

int GameDesk::rowCount(const QModelIndex &parent) const
{
//    if (!parent.isValid())
//        return 9;
//    return DESK_SIZE;
//    Q_UNUSED(parent);

    return DESK_SIZE * DESK_SIZE;
}

int GameDesk::columnCount(const QModelIndex &parent) const
{
//    if (!parent.isValid())
//        return 9;
    return DESK_SIZE;
}

QVariant GameDesk::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

//    if (index.row() > rowCount() || index.column() > columnCount())
//            return QVariant();

        if (role == Roles::BallRole)
        {
            qDebug() << gameDesk[index.row()]->getBall() << " - " << QVariant(gameDesk[index.row()]->getBall());
            qDebug() << "Row - " << index.row() << " COloumt - " << index.column();
            return QVariant(gameDesk[index.row()]->getBall());
        }

        if (role == Roles::second)
        {
            qDebug() << gameDesk[index.row()]->getBall() << " - " << QVariant(gameDesk[index.row()]->getBall());
            qDebug() << "Row - " << index.row() << " COloumt - " << index.column();
            return QVariant(gameDesk[index.row()]->getBall());
        }
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

    if (role == Roles::BallRole)
    {
        gameDesk[index.row()]->setBall(value.toInt());

        emit dataChanged(index, index, {role});
        qDebug() << "new value - " << value;
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
//            if (gameDesk[i][j]->getBall() == Colors::none)
//                result.push_back(index(i, j));
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
//            if (gameDesk[i][j]->getBall() == Colors::none)
//            {
//                currentColor = Colors::none;
//                counter = 0;
//                continue;
//            }

//            if (!(currentColor == gameDesk[i][j]->getBall()))
//            {
//                currentColor = gameDesk[i][j]->getBall();
//                counter = 1;
//            }
//            else counter++;

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
//            if (gameDesk[i][j]->getBall() == Colors::none)
//            {

//                currentColor = Colors::none;
//                counter = 0;
//                continue;
//            }

//            if (!(currentColor == gameDesk[i][j]->getBall()))
//            {
//                currentColor = gameDesk[i][j]->getBall();
//                counter = 1;
//            }
//            else counter++;

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

void GameDesk::init()
{

}

QVector<QModelIndex> GameDesk::getAllModelIndexes()
{
    QVector<QModelIndex> result;

    for (int i = 0; i < DESK_SIZE; i++)
        for (int j = 0; j < DESK_SIZE; j++)
                result.push_back(index(i, j));

    return result;
}

int GameDesk::makeSomething()
{
    return 1;
}
