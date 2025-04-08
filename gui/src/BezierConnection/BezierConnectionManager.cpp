#include "BezierConnectionManager.h"

#include "Serialization/BlockReader.h"

BezierConnectionManager* BezierConnectionManager::instance()
{
    static BezierConnectionManager manager;
    return &manager;
}

BezierConnectionManager::BezierConnectionManager(QObject* parent) : QObject(parent)
{
}

void BezierConnectionManager::registerBezierConnection(QQuickItem* connection)
{
    if (connection && !m_connections.contains(connection))
    {
        m_connections.append(connection);

        connect(connection, &QObject::destroyed, this,
            [this, connection]() { m_connections.removeAll(connection); });
    }
}

void BezierConnectionManager::unregisterBezierConnection(QQuickItem* block)
{
    m_connections.removeAll(block);
}