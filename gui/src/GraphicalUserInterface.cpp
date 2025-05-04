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

    initializeInstances(engine);

    prepareContexts(engine);

    loadEngine(app, engine);

    return QGuiApplication::exec();
}

void GraphicalUserInterface::initializeInstances(QQmlApplicationEngine& engine)
{
    guiController = std::make_shared<GuiController>(this->parser, this->interpreter);
    blockDiagramFactory = std::make_shared<BlockDiagramFactory>(&engine);
    bezierConnectionFactoryCPP = std::make_shared<BezierConnectionFactory>(&engine);
    anchorFactory = std::make_shared<AnchorFactory>(&engine);
}

void GraphicalUserInterface::prepareContexts(QQmlApplicationEngine& engine) const
{
    qmlRegisterType<Anchor>("Anchor", 1, 0, "Anchor");
    qmlRegisterType<BlockDiagram>("BlockDiagram", 1, 0, "BlockDiagram");
    qmlRegisterType<BezierConnection>("BezierConnection", 1, 0, "BezierConnection");
    qmlRegisterSingletonType(QUrl("qrc:/qml/Theme.qml"), "Theme", 1, 0, "Theme");

    engine.rootContext()->setContextProperty("blockDiagramFactory", blockDiagramFactory.get());
    engine.rootContext()->setContextProperty("bezierConnectionFactoryCPP", bezierConnectionFactoryCPP.get());
    engine.rootContext()->setContextProperty("anchorFactory", anchorFactory.get());

    qmlRegisterSingletonInstance<CollisionManager>("CollisionManager", 1, 0, "CollisionManager",
                                                   CollisionManager::instance());
    qmlRegisterSingletonInstance<BlockDiagramManager>("BlockDiagramManager", 1, 0, "BlockDiagramManager",
                                                      BlockDiagramManager::instance());
    qmlRegisterSingletonInstance<ProgramSerializator>("ProgramSerializator", 1, 0, "ProgramSerializator",
                                                      ProgramSerializator::instance());
    qmlRegisterSingletonInstance<GuiController>("GuiController", 1, 0, "GuiController",
                                                  guiController.get());
}

void GraphicalUserInterface::loadEngine(const QGuiApplication& app, QQmlApplicationEngine& engine)
{
    auto connection = QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [this](QObject const* obj, const QUrl& objUrl)
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

    if (!initializedSuccessfully(engine)) {
        throw std::runtime_error("Failed to load QML file");
    }
}

bool GraphicalUserInterface::initializedSuccessfully(QQmlApplicationEngine& engine)
{
    return !engine.rootObjects().isEmpty();
}