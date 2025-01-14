#include "CollisionManager.h"

CollisionManager* CollisionManager::instance() {
    static CollisionManager manager;
    return &manager;
}

CollisionManager::CollisionManager(QObject* parent) : QObject(parent) {}

void CollisionManager::registerAnchor(QQuickItem* anchor) {
    if (anchor && !m_anchors.contains(anchor)) {
        m_anchors.append(anchor);
    }
}

void CollisionManager::unregisterAnchor(QQuickItem* anchor) {
    m_anchors.removeAll(anchor);
}

bool CollisionManager::isColliding(QQuickItem* a, QQuickItem* b) {
    if (!a || !b)
        return false;

    return a->x() < b->x() + b->width() &&
           a->x() + a->width() > b->x() &&
           a->y() < b->y() + b->height() &&
           a->y() + a->height() > b->y();
}

QQuickItem* CollisionManager::checkCollision(QQuickItem* movable) {
    for (QQuickItem* anchor : m_anchors) {
        if (isColliding(movable, anchor)) {
            return anchor;
        }
    }
    return nullptr;
}
