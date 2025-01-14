#include "CollisionManager.h"

CollisionManager* CollisionManager::instance()
{
    static CollisionManager manager;
    return &manager;
}

CollisionManager::CollisionManager(QObject* parent) : QObject(parent)
{
}

void CollisionManager::registerAnchor(QQuickItem* anchor)
{
    if (anchor && !m_anchors.contains(anchor))
    {
        m_anchors.append(anchor);
    }
}

void CollisionManager::unregisterAnchor(QQuickItem* anchor)
{
    m_anchors.removeAll(anchor);
}

bool CollisionManager::isColliding(QQuickItem* a, QQuickItem* b)
{
    if (!a || !b)
    {
        return false;
    }

    if (!a->parentItem() || !b->parentItem())
    {
        return false;
    }

    if (!a->window() || !b->window())
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


QQuickItem* CollisionManager::checkCollision(QQuickItem* movable)
{
    for (QQuickItem* anchor : m_anchors)
    {
        if (isColliding(movable, anchor))
        {
            return anchor;
        }
    }
    return nullptr;
}
