#include "CollisionManager.h"

#include <QUuid>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#include "Blocks/Connection.h"
#include "Serialization/ConnectionReader.h"

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
        // Generate and assign UUID
        if (!anchor->property("anchorId").isValid()) {
            QUuid uuid = QUuid::createUuid();
            anchor->setProperty("anchorId", uuid.toString(QUuid::WithoutBraces));
        }

        m_anchors.append(anchor);

        // Ensure we remove the anchor when it is destroyed
        connect(anchor, &QObject::destroyed, this, [this, anchor]() {
            m_anchors.removeAll(anchor);
        });
    }
}

void CollisionManager::unregisterAnchor(QQuickItem* anchor)
{
    m_anchors.removeAll(anchor);
}

bool CollisionManager::isColliding(QQuickItem* a, QQuickItem* b)
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

QQuickItem* CollisionManager::checkCollision(QQuickItem* movable)
{
    for (const QPointer<QQuickItem>& anchor : m_anchors)
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

QQuickItem* CollisionManager::isOverAnAnchor(int x, int y, QQuickItem* excludeItem)
{
    for (const QPointer<QQuickItem>& anchor : m_anchors)
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

bool CollisionManager::isColliding(int x, int y, QQuickItem* b)
{
    if (!b || !b->parentItem())
    {
        return false;
    }

    QRectF rectB = b->mapRectToScene(b->boundingRect());
    return rectB.contains(x, y);
}
