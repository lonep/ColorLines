#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QObject>
#include "gamedesk.h"

class GameLogic : public QObject
{
    Q_OBJECT
public:

    virtual void addStartCondition() = 0;

    virtual void newGame() = 0;
    virtual void gameMove() = 0;

//    GameMoveData - данные, которые неизменны и добавляются на каждом шаге игры
    virtual void addGameMoveData() = 0;

    virtual QModelIndexList findWinCombination() = 0;
    virtual void cleanGameDesk() = 0;

    //Взаимодействие с данными
    virtual void setGameModel(QAbstractItemModel *model);
    virtual void setGameModel(GameDesk *model);

    virtual void setGameDeskCellAmount(int amount);
    virtual void setWinCombination(int combination);

    virtual int getGameDeskCellsAmount() const;
    virtual int getWinCombination() const;

    virtual int getGameDeskColumnCount() const;
    virtual void setGameDeskColumnCount(int newGameDeskColumnCount);

protected:

    //Общее кол-во клеток на игровом поле.
    int gameDeskCellsAmount;
    int gameDeskColumnCount;

    //Кол-во элементов в ряд в выигрышной комбинации.
    int winCombination;

    GameDesk *gameModel;

signals:

};

#endif // GAMELOGIC_H
