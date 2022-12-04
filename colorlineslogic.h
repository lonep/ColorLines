#ifndef COLORLINESLOGIC_H
#define COLORLINESLOGIC_H

#include "gamelogic.h"
#include <QObject>

class ColorLinesLogic : public GameLogic
{
public:
    ColorLinesLogic(QAbstractItemModel *modelPtr = nullptr, int deskColumnAmount = 0, int winCombination = 0);

    //Игровая логика
   Q_INVOKABLE virtual void addStartCondition() override;
   Q_INVOKABLE virtual void addGameMoveData() override;
   virtual QModelIndexList findWinCombination() override;

};

#endif // COLORLINESLOGIC_H
