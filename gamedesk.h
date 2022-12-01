#ifndef GAMEDESK_H
#define GAMEDESK_H

#include <QAbstractItemModel>
#include <QVector>
#include <QPair>

#include "gamecell.h"

class GameDesk : public QAbstractItemModel
{
    Q_OBJECT


public:
    explicit GameDesk(QObject *parent = nullptr);
    ~GameDesk();

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;

    QModelIndex parent(const QModelIndex &child) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QVector <QModelIndex> getEmptyCells();

    virtual QVector <QModelIndex> findWinRow();

    int makeSomething();

private:
    QVector <QVector<GameCell*>> gameDesk;

    const int DESK_SIZE = 9;
    const int WIN_NUMBER_IN_ROW = 5;
};

#endif // GAMEDESK_H
