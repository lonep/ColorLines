#ifndef GAMECELL_H
#define GAMECELL_H

#include "Colors.h"

class GameCell
{

public:


    GameCell(Colors type = Colors::none); //Q_Property
    GameCell(int value);


    int getBall() const;
    void setBall(Colors type);

    void setBall(int type);

private:
    int ballType;
};

#endif // GAMECELL_H
