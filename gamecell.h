#ifndef GAMECELL_H
#define GAMECELL_H

#include "Colors.h"

class GameCell
{

public:


    GameCell(Colors type = Colors::none);

    int getBall() const;
    void setBall(Colors type);

    void setBall(int type);

private:
    int ballType;
};

#endif // GAMECELL_H
