#include "randomizer.h"

#include <QRandomGenerator>
#include <QDebug>

Randomizer::Randomizer()
{


}

//template<typename T>
Colors Randomizer::randomColor()
{
    return Colors(QRandomGenerator::global()->bounded(Colors::none + 1, Colors::LAST)); // Plus 1 to none because none value isn't color
}


QVector<Colors> Randomizer::randomColors(int colorAmount)
{
    QVector <Colors> result;
    for (int i = 0; i < colorAmount; i ++)
        result.push_back(Colors(QRandomGenerator::global()->bounded(Colors::none + 1, Colors::LAST)));

    return result;
}

QVector<QModelIndex> Randomizer::chooseRandomCells(QVector<QModelIndex> emptyCellsCoordinates, int cellsAmount)
{
    QVector<QModelIndex> result;

    int emptyCellIndex;

    try
        {
        if (cellsAmount < emptyCellsCoordinates.size())
            for (int i = 0; i < cellsAmount; i++)
            {
                emptyCellIndex = QRandomGenerator::global()->bounded(0, emptyCellsCoordinates.size());
                result.push_back(emptyCellsCoordinates[emptyCellIndex]);
                emptyCellsCoordinates.removeAt(emptyCellIndex);
            }
        else throw (cellsAmount);
    }
    catch (int Number)
    {
        qCritical() << "The required number of cells " << Number << " is greater than the number of free ones.";
    }

    return result;
}

