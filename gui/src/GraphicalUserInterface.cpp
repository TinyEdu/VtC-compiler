#include "GraphicalUserInterface.h"

#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QtCore/QUrl>
#include <QtCore/QString>

#include "Anchor/Anchor.h"
#include "Anchor/AnchorFactory.h"
#include "Collision/CollisionManager.h"
#include "MovableBlock/MovableBlock.h"
#include "MovableBlock/MovableBlockFactory.h"


int GraphicalUserInterface::run(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    MovableBlockFactory movableBlockFactory(&engine);
    engine.rootContext()->setContextProperty("blockFactory", &movableBlockFactory);

    AnchorFactory anchorFactory(&engine);
    engine.rootContext()->setContextProperty("anchorFactory", &anchorFactory);


    qmlRegisterType<MovableBlock>("MovableBlock", 1, 0, "MovableBlock");
    qmlRegisterType<Anchor>("Anchor", 1, 0, "Anchor");
    qmlRegisterSingletonInstance<CollisionManager>("CollisionManager", 1, 0, "CollisionManager",
                                                   CollisionManager::instance());


    auto url = QUrl(QStringLiteral("qrc:qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject* obj, const QUrl& objUrl)
                     {
                         if (!obj && url == objUrl)
                             QCoreApplication::exit(-1);
                     }, Qt::QueuedConnection);

    // QML import paths for the Qt6 libraries from vcpkg
    const QString relativeImportPath = QCoreApplication::applicationDirPath() +
        "/../vcpkg_installed/x64-windows/debug/Qt6/qml";

    engine.addImportPath(relativeImportPath);

    engine.load(url);

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
