#include "GraphicalUserInterface.h"

#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QtCore/QUrl>
#include <QtCore/QString>
#include <QLoggingCategory>

#include "Anchor/Anchor.h"
#include "Anchor/AnchorFactory.h"
#include "BlockDiagram/BlockDiagramFactory.h"
#include "BlockDiagramManager/BlockDiagramManager.h"
#include "Collision/CollisionManager.h"
#include "MovableBlock/MovableBlock.h"
#include "MovableBlock/MovableBlockFactory.h"
#include "Serialization/ProgramSerializator.h"
#include "BezierConnection/BezierConnectionFactory.h"

int GraphicalUserInterface::run(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QLoggingCategory::setFilterRules("qt.qml.debug=true");
    qmlRegisterType<Anchor>("Anchor", 1, 0, "Anchor");
    qmlRegisterType<BlockDiagram>("BlockDiagram", 1, 0, "BlockDiagram");

    ProgramSerializator serializator(&engine);
    engine.rootContext()->setContextProperty("ProgramSerializator", &serializator);

    BlockDiagramFactory blockDiagramFactory(&engine);
    engine.rootContext()->setContextProperty("blockDiagramFactory", &blockDiagramFactory);

    BezierConnectionFactory bezierConnectionFactory(&engine);
    engine.rootContext()->setContextProperty("bezierConnectionFactory", &bezierConnectionFactory);

    AnchorFactory anchorFactory(&engine);
    engine.rootContext()->setContextProperty("anchorFactory", &anchorFactory);

    qmlRegisterSingletonInstance<CollisionManager>("CollisionManager", 1, 0, "CollisionManager",
                                                   CollisionManager::instance());
    qmlRegisterSingletonInstance<BlockDiagramManager>("BlockDiagramManager", 1, 0, "BlockDiagramManager",
                                                   BlockDiagramManager::instance());

    auto url = QUrl(QStringLiteral("qrc:qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject* obj, const QUrl& objUrl)
                     {
                         if (!obj && url == objUrl)
                             QCoreApplication::exit(-1);
                     }, Qt::QueuedConnection);

    // Specifying a native qml style
    qputenv("QT_QUICK_CONTROLS_STYLE", "Fusion");

    // QML import paths for the Qt6 libraries from vcpkg
    const QString relativeImportPath = QCoreApplication::applicationDirPath() +
        "/../vcpkg_installed/x64-windows/debug/Qt6/qml";

    engine.addImportPath(relativeImportPath);

    engine.load(url);

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
