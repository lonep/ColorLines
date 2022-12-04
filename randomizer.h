#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <QVector>
#include "Colors.h"
#include "qabstractitemmodel.h"

class Randomizer
{
public:
    Randomizer();


    static Colors randomColor();
    static QList<Colors> randomColors(int colorAmount);

    static QList<QModelIndex> chooseRandomCells(QList<QModelIndex> emptyCellsCoordinates, int cellsAmount);
};

#endif // RANDOMIZER_H
