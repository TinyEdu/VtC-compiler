#include "GuiMain.h"

#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QtCore/QUrl>
#include <QtCore/QString>

#include "Anchor/Anchor.h"
#include "Collision/CollisionManager.h"
#include "MovableBlock/MovableBlock.h"
#include "MovableBlock/MovableBlockFactory.h"


using namespace Qt::StringLiterals;

int GuiMain::run(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    MovableBlockFactory movableBlockFactory(&engine);
    engine.rootContext()->setContextProperty("blockFactory", &movableBlockFactory);


    qmlRegisterType<MovableBlock>("MovableBlock", 1, 0, "MovableBlock");
    qmlRegisterType<Anchor>("Anchor", 1, 0, "Anchor");
    qmlRegisterSingletonInstance<CollisionManager>("CollisionManager", 1, 0, "CollisionManager",
                                                   CollisionManager::instance());


    auto url = QUrl(QStringLiteral("qrc:/qt/qml/cpp/MovableBlock/gui/qmls/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject* obj, const QUrl& objUrl)
                     {
                         if (!obj && url == objUrl)
                             QCoreApplication::exit(-1);
                     }, Qt::QueuedConnection);
    engine.load(url);


    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
