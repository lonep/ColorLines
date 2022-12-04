#ifndef COLORLINESLOGIC_H
#define COLORLINESLOGIC_H

#include "gamelogic.h"
#include <QObject>

class ColorLinesLogic : public GameLogic
{
public:
    ColorLinesLogic(QAbstractItemModel *modelPtr = nullptr, int deskColumnAmount = 0, int winCombination = 0);

    //Игровая логика
   virtual void addStartCondition() override;
   virtual void addGameMoveData() override;
   virtual QModelIndexList findWinCombination() override;

    Q_INVOKABLE virtual void newGame() override;
    Q_INVOKABLE virtual void gameMove() override;

    virtual void cleanGameDesk() override;
};

#endif // COLORLINESLOGIC_H
