#include "gamelogic.h"

void GameLogic::setGameModel(QAbstractItemModel *model)
{

}

void GameLogic::setGameModel(GameDesk *model)
{
    gameModel = model;
}

void GameLogic::setGameDeskCellAmount(int amount)
{
    gameDeskCellsAmount = amount;
}


void GameLogic::setWinCombination(int combination)
{
    winCombination = combination;
}

int GameLogic::getGameDeskCellsAmount() const
{
    return gameDeskCellsAmount;
}

int GameLogic::getWinCombination() const
{
    return winCombination;
}

int GameLogic::getGameDeskColumnCount() const
{
    return gameDeskColumnCount;
}

void GameLogic::setGameDeskColumnCount(int newGameDeskColumnCount)
{
    gameDeskColumnCount = newGameDeskColumnCount;
}
