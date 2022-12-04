#ifndef GAMEDESK_H
#define GAMEDESK_H

#include <QAbstractItemModel>
#include <QVector>

#include "gamecell.h"

class GameDesk : public QAbstractItemModel
{
    Q_OBJECT


public:
    explicit GameDesk(QObject *parent = nullptr);
    ~GameDesk();

    enum Roles {
        BallRole = Qt::UserRole,
        NextBallsRole
    };

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    QModelIndex parent(const QModelIndex &child) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void clearData(const QModelIndex &index, int role = Qt::DisplayRole);

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;


    Qt::ItemFlags flags(const QModelIndex& index) const override;
    virtual void clearCells(const QVector <QModelIndex> &cells);

    QModelIndexList getAllModelIndexes();

    void init(int deskSize = 0);
    void init(const QList <GameCell*> &gameData);

private:
//    ������� ���� �� ������������ ��������� ���������, ��� � � ������ � ������,
//    �� � ���� �� ������� ��������� ��������� ��� � GridView, ������� ��� QList.
//    �� ���� ������� �������� ����-�� ������� ������� ����� �� QAbstractListModel,
//    �� � ����� �������� ����� �� �� � �������� � column = 0
    QList <GameCell*> gameDesk;

//    � ������� ����� ������ ������������ ����, ������� �������� �� ����. ����
    QList <Colors> nextMoveItems;


    void init(QModelIndexList indexList);


    int DESK_SIZE;



};

#endif // GAMEDESK_H
