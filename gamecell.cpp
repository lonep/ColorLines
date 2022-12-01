#include "gamecell.h"



GameCell::GameCell(Colors type)
{
    ballType = type;
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

