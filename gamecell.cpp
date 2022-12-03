#include "gamecell.h"



GameCell::GameCell(Colors type)
{
    ballType = type;
}

GameCell::GameCell(int value)
{
    ballType = value;
}

int GameCell::getBall() const
{
    return ballType;
}

void GameCell::setBall(Colors type)
{
    ballType = type;
}

void GameCell::setBall(int type)
{
    ballType = type;
}

