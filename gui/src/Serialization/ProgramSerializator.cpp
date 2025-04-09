#include "ProgramSerializator.h"

#include "BlockReader.h"
#include "ConnectionReader.h"
#include "BlockDiagramManager/BlockDiagramManager.h"
#include "Collision/CollisionManager.h"

#include <QJsonArray>
#include <QJsonDocument>

#include "BezierConnection/BezierConnectionManager.h"


ProgramSerializator* ProgramSerializator::instance()
{
    static ProgramSerializator instance;
    return &instance;
}

void ProgramSerializator::save()
{
    QJsonObject root;
    root = readBlocks(root);
    root = readConnections(root);

    // Temporary: print the JSON to the console
    const QJsonDocument doc(root);
    parser->parse(QString::fromUtf8(doc.toJson()).toStdString());

    qDebug().noquote() << doc.toJson(QJsonDocument::Indented);
}

void ProgramSerializator::load()
{
}

QJsonObject ProgramSerializator::readBlocks(QJsonObject root)
{
    QJsonArray blocksArray;
    QList<QPointer<QQuickItem>> blocks = BlockDiagramManager::instance()->getBlocks();
    for (const QPointer<QQuickItem>& item : blocks)
    {
        if (!item) continue;

        Block const* block = BlockReader::Instance()->extract(item);
        if (!block) continue;

        blocksArray.append(block->toJson());
    }

    root["Blocks"] = blocksArray;
    return root;
}

QJsonObject ProgramSerializator::readConnections(QJsonObject root)
{
    QJsonArray connectionsArray;

    QList<QPointer<QQuickItem>> anchors = BezierConnectionManager::instance()->getConnections();
    for (const QPointer<QQuickItem>& item : anchors)
    {
        if (!item) continue;
        Connection const* conn = ConnectionReader::Instance()->extract(item);
        if (conn)
        {
            connectionsArray.append(conn->toJson());
        }
    }

    root["Connections"] = connectionsArray;
    return root;
}
