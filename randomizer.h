#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <QVector>
#include "Colors.h"

class Randomizer
{
public:
    Randomizer();


    static Colors randomColor();
    static QVector<Colors> randomColors(int colorAmount);

    static QVector<QPair<int, int>> chooseRandomCells(QVector<QPair<int, int>> emptyCellsCoordinates, int cellsAmount);
};

#endif // RANDOMIZER_H
