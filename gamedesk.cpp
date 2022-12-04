#include "gamedesk.h"
#include "Colors.h"
#include "dbmanager.h"
#include <QDebug>

GameDesk::GameDesk(QObject *parent)
    : QAbstractItemModel(parent)
{
    init(81);

//    »з-за проблемы, описанной в ReadMe здесь пока стоит заглушка,
//            чтобы можно было хот€ бы подвигать кружочки.
    {
    setData(index(3, 0), Colors::green, Roles::BallRole);
    setData(index(4, 0), Colors::yellow, Roles::BallRole);
    setData(index(5, 0), Colors::red, Roles::BallRole);
    setData(index(6, 0), Colors::orange, Roles::BallRole);
    }

}

GameDesk::~GameDesk()
{
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
    roles[Roles::NextBallsRole] = "nextBall";

    return roles;
}

QModelIndex GameDesk::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);
}

int GameDesk::rowCount(const QModelIndex &parent) const
{
    return DESK_SIZE;
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

Qt::ItemFlags GameDesk::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable; // FIXME: Implement me!
}

void GameDesk::clearCells(const QVector<QModelIndex> &cells)
{
    foreach (auto it, cells)
    {
        clearData(it);
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


