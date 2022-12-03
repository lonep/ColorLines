#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "gamedesk.h"
#include "gamecell.h"
#include "Colors.h"
#include "randomizer.h"
#include "dbmanager.h"
#include <QQuickView>
#include <QQmlContext>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<GameDesk>("GameDesk", 1, 0, "GameDeskModel");

    const QUrl url(u"qrc:/ColorLines/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);



    GameDesk desk;
    DBmanager db("gameDB.db");


//   foreach (auto it, db.getData())
//        qDebug() << it->getBall();

//    qDebug() << desk.findWinRow().size();

   QStringList dataList;

   for (int i = 0 ; i < 81; i++)
   {
       dataList.push_back(QString("Item %1").arg(i));
   }

   engine.rootContext()->setContextProperty("myModel", &desk);



    return app.exec();
}
