#include "gamedesk.h"
#include "Colors.h"
#include "randomizer.h"
#include "dbmanager.h"
#include <QDebug>

GameDesk::GameDesk(QObject *parent)
    : QAbstractItemModel(parent)
{
    DBmanager db("gameDB.db");
    QVector<GameCell*> data = db.getData();
    init();

//    for (int i = 0 ; i < DESK_SIZE * DESK_SIZE; i++)
//    {
//        setData(index(i, 0), data[i]->getBall(), Roles::BallRole);
//    }
    addStartItems();


}

GameDesk::~GameDesk()
{
    DBmanager db("gameDB.db");
    db.saveData(getAllModelIndexes());
    gameDesk.clear();
}


QModelIndex GameDesk::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(parent);

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
    Q_UNUSED(child);
}

int GameDesk::rowCount(const QModelIndex &parent) const
{
    return DESK_SIZE * DESK_SIZE;
}

int GameDesk::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 0;
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
     else   return QVariant();
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

        emit dataChanged(index, index, QList<int>(BallRole));
        qDebug() << "new value - " << value;
        return true;
    }
    return false;

}

void GameDesk::addStartItems()
{
    updateData(Randomizer::chooseRandomCells(getEmptyCells(), 5), Randomizer::randomColors(5));
}

void GameDesk::addStepItems()
{
    updateData(Randomizer::chooseRandomCells(getEmptyCells(), 3), Randomizer::randomColors(3));
    qDebug() << "CALL ADDSTEPITEMS";
}

Qt::ItemFlags GameDesk::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable; // FIXME: Implement me!
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

void GameDesk::updateData(const QVector<QModelIndex> &cells, const QVector<Colors> &colors)
{
    if (cells.size() == colors.size())
    {
        for (int i = 0; i < cells.size(); i++)
            setData(cells[i], colors[i], Roles::BallRole);
    }
}

void GameDesk::init(int deskSize)
{
    DESK_SIZE = deskSize;

    for (int i = 0; i < DESK_SIZE; i++)// TODO fix constructor
        gameDesk.push_back(new GameCell(Colors::none));
}

void GameDesk::init(const QList<GameCell*> &gameData)
{
    gameDesk = gameData;
}

QModelIndexList GameDesk::getAllModelIndexes()
{
    QModelIndexList result;


    try {
        if (DESK_SIZE != 0)
            for (int i = 0; i < DESK_SIZE; i++)
                    result.push_back(index(i, 0));
        else throw (DESK_SIZE);
    } catch (int size)
    {
            qCritical() << "Model not initialized. Actual game desk size: " << size;
            return result;
    }

    return result;
}


