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
        second
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

    Q_INVOKABLE virtual void addStartItems();
    Q_INVOKABLE virtual void addStepItems();

    Qt::ItemFlags flags(const QModelIndex& index) const override;


    virtual QVector <QModelIndex> findWinRow();
    virtual void clearCells(const QVector <QModelIndex> &cells);
    virtual void updateData(const QVector <QModelIndex> &cells, const QVector<Colors> &colors);

    QModelIndexList getAllModelIndexes();

    void init(int deskSize = 0);
    void init(const QList <GameCell*> &gameData);

private:
//    Ћогично было бы использовать двумерный контейнер, как € с начала и сделал,
//    но у мен€ не удалось корректно подружить его с GridView, поэтому тут QList.
//    ѕо этой причине логичнее было-бы сменить базовый класс на QAbstractListModel,
//    но € решил оставить класс из “« и работать с column = 0
    QList <GameCell*> gameDesk;


    void init(QModelIndexList indexList);


    int DESK_SIZE;



};

#endif // GAMEDESK_H
