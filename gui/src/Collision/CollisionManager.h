#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <QQuickItem>
#include <QPointer>
#include <QList>

class CollisionManager : public QObject
{
    Q_OBJECT

public:
    static CollisionManager* instance();
    void registerAnchor(QQuickItem* anchor);
    void unregisterAnchor(QQuickItem* anchor);

    Q_INVOKABLE void save();

    Q_INVOKABLE QQuickItem* checkCollision(QQuickItem* movable);
    Q_INVOKABLE QQuickItem* isOverAnAnchor(int x, int y, QQuickItem* excludeItem);

private:
    explicit CollisionManager(QObject* parent = nullptr);

    bool isColliding(QQuickItem* a, QQuickItem* b);
    bool isColliding(int x, int y, QQuickItem* b);

    QList<QPointer<QQuickItem>> m_anchors;
};

#endif // COLLISIONMANAGER_H
