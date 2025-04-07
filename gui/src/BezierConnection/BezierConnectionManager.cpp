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

void BezierConnectionManager::registerBezierConnection(QQuickItem* block)
{
    if (block && !m_connections.contains(block))
    {
        m_connections.append(block);

        connect(block, &QObject::destroyed, this, [this, block]() {
            m_connections.removeAll(block);
        });
    }
}

void BezierConnectionManager::unregisterBezierConnection(QQuickItem* block)
{
    m_connections.removeAll(block);
}