#include "colorlineslogic.h"
#include "randomizer.h"

ColorLinesLogic::ColorLinesLogic(QAbstractItemModel *modelPtr, int deskColumnAmount, int winCombination)
{
    setGameModel(modelPtr);
    setGameDeskCellAmount(deskColumnAmount * deskColumnAmount); //Поле имеет одинаковые стороны
    setWinCombination(winCombination);

    setGameDeskColumnCount(deskColumnAmount);
}

void ColorLinesLogic::addStartCondition()
{
    int startElementsAmount = 5;
    QModelIndexList data = gameModel->getAllModelIndexes();

    QModelIndexList result = Randomizer::chooseRandomCells(data, startElementsAmount);

    foreach (auto it, result)
    {
        gameModel->setData(it, Randomizer::randomColor(), GameDesk::Roles::BallRole);
    }

}

void ColorLinesLogic::addGameMoveData()
{
    int gameMoveElementAmount = 3;
    QModelIndexList data;


    //Получаем список пустых клеток игрового поля.
    for (int i = 0; i < getGameDeskCellsAmount(); i++)
    {
        if (gameModel->data(gameModel->index(i, 0), GameDesk::Roles::BallRole) == Colors::none)
            data.push_back(gameModel->index(i, 0));
    }

    QModelIndexList result = Randomizer::chooseRandomCells(data, gameMoveElementAmount);

    foreach (auto it, result)
    {
        gameModel->setData(it, Randomizer::randomColor(), GameDesk::Roles::BallRole);
    }

    qDebug() << "---------------Added new three balls-------------";
}

QModelIndexList ColorLinesLogic::findWinCombination()
{
    QList<QModelIndexList> result2D;

    QModelIndexList data = gameModel->getAllModelIndexes();

    for (int i = 0; i < getGameDeskColumnCount(); i++)
    {
        QModelIndexList indexList;
        for (int j = i * getGameDeskCellsAmount(); j < getGameDeskColumnCount() * i+1; j++)
        {
            indexList.push_back(data[i]);
        }
        result2D.push_back(indexList);
    }

    int counter = 0;
    int currentColor = 0;

    QModelIndexList result;

    for (int i = 0; i < getGameDeskColumnCount(); i++) //Find win row by horizonal
    {
        for (int j = 0; j < getGameDeskColumnCount(); j++)
        {
            if (gameModel->data(result2D[i][j], GameDesk::Roles::BallRole) == Colors::none)
            {
                currentColor = Colors::none;
                counter = 0;
                continue;
            }

            if (!(currentColor == gameModel->data(result2D[i][j], GameDesk::Roles::BallRole)))
            {
                currentColor = gameModel->data(result2D[i][j], GameDesk::Roles::BallRole).toInt();
                counter = 1;
            }
            else counter++;

            if (counter == getWinCombination())
            {
                for (int k = j; k >= 0; k--)
                    result.push_back(gameModel->index(i*k, 0)); //Приводим к одномерному виду
                counter = 0;
            }
        }
    }

    for (int j = 0; j < getGameDeskColumnCount(); j++) //Find win row by vertical
    {
        for (int i = 0; i < getGameDeskColumnCount(); i++)
        {
            if (gameModel->data(result2D[i][j], GameDesk::Roles::BallRole) == Colors::none)
            {

                currentColor = Colors::none;
                counter = 0;
                continue;
            }

            if (!(currentColor == gameModel->data(result2D[i][j], GameDesk::Roles::BallRole)))
            {
                currentColor = gameModel->data(result2D[i][j], GameDesk::Roles::BallRole).toInt();
                counter = 1;
            }
            else counter++;

            if (counter == getWinCombination())
            {
                for (int k = i; k >= 0; k--)
                    result.push_back(gameModel->index(k*j, 0)); //Приводим к одномерному виду
                counter = 0;
            }
        }
    }



    return result;

}

void ColorLinesLogic::newGame()
{
    cleanGameDesk();
    addStartCondition();
    //ToDo clean total score;
}

void ColorLinesLogic::gameMove()
{
    addGameMoveData();
}

void ColorLinesLogic::cleanGameDesk()
{
    QModelIndexList data = gameModel->getAllModelIndexes();

    foreach(auto it, data)
    {
        gameModel->setData(it, Colors::none, GameDesk::Roles::BallRole);
    }

}

