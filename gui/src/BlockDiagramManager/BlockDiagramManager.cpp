#include "BlockDiagramManager.h"

#include "Serialization/BlockReader.h"
#include <QJsonArray>
#include <QJsonDocument>

BlockDiagramManager* BlockDiagramManager::instance()
{
    static BlockDiagramManager manager;
    return &manager;
}

BlockDiagramManager::BlockDiagramManager(QObject* parent) : QObject(parent)
{
}

void BlockDiagramManager::registerBlockDiagram(QQuickItem* block)
{
    if (block && !m_blocks.contains(block))
    {
        m_blocks.append(block);

        connect(block, &QObject::destroyed, this, [this, block]() {
            m_blocks.removeAll(block);
        });
    }
}

void BlockDiagramManager::unregisterBlockDiagram(QQuickItem* block)
{
    m_blocks.removeAll(block);
}

bool BlockDiagramManager::isColliding(QQuickItem* a, QQuickItem* b)
{
    if (!a || !b || !a->parentItem() || !b->parentItem() || !a->window() || !b->window())
    {
        return false;
    }

    if (a->width() <= 0 || a->height() <= 0 || b->width() <= 0 || b->height() <= 0)
    {
        return false;
    }

    QRectF rectA = a->mapRectToScene(a->boundingRect());
    QRectF rectB = b->mapRectToScene(b->boundingRect());

    return rectA.intersects(rectB);
}

QQuickItem* BlockDiagramManager::checkCollision(QQuickItem* movable)
{
    for (const QPointer<QQuickItem>& anchor : m_blocks)
    {
        if (!anchor || anchor == movable)
            continue;

        if (isColliding(movable, anchor))
        {
            return anchor;
        }
    }
    return nullptr;
}

QQuickItem* BlockDiagramManager::isOverAnAnchor(int x, int y, QQuickItem* excludeItem)
{
    for (const QPointer<QQuickItem>& anchor : m_blocks)
    {
        if (!anchor || anchor == excludeItem)
            continue;

        if (isColliding(x, y, anchor))
        {
            return anchor;
        }
    }

    return nullptr;
}

bool BlockDiagramManager::isColliding(int x, int y, QQuickItem* b)
{
    if (!b || !b->parentItem())
    {
        return false;
    }

    QRectF rectB = b->mapRectToScene(b->boundingRect());
    return rectB.contains(x, y);
}
