#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "gamedesk.h"
#include "gamecell.h"
#include "Colors.h"
#include "randomizer.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/ColorLines/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    GameDesk desk;

    return app.exec();
}
