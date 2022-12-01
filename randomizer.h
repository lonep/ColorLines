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
    static QVector<Colors> randomColors(int colorAmount);

    static QVector<QModelIndex> chooseRandomCells(QVector<QModelIndex> emptyCellsCoordinates, int cellsAmount);
};

#endif // RANDOMIZER_H
