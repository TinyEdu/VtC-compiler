#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <QQuickItem>
#include <QList>

class CollisionManager : public QObject {
    Q_OBJECT

public:
    static CollisionManager* instance();
    void registerAnchor(QQuickItem* anchor);
    void unregisterAnchor(QQuickItem* anchor);

    Q_INVOKABLE QQuickItem* checkCollision(QQuickItem* movable);

private:
    explicit CollisionManager(QObject* parent = nullptr);
    QList<QQuickItem*> m_anchors;
    bool isColliding(QQuickItem* a, QQuickItem* b);
};

#endif // COLLISIONMANAGER_H
