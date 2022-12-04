#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "gamedesk.h"
#include "dbmanager.h"
#include <QQuickView>
#include <QQmlContext>
#include <colorlineslogic.h>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    GameDesk *desk = new GameDesk;

    ColorLinesLogic *gameLogic = new ColorLinesLogic(desk, 9, 5);

    DBmanager db("gameDB.db");

    qmlRegisterType<GameDesk>("GameDesk", 1, 0, "GameDeskModel");

    const QUrl url(u"qrc:/ColorLines/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    engine.rootContext()->setContextProperty("gameDesk", desk);
    engine.rootContext()->setContextProperty("gameLogic", gameLogic);


    return app.exec();
}
