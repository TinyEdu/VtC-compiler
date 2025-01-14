#ifndef MOVABLEBLOCK_H
#define MOVABLEBLOCK_H

#include <QQuickItem>
#include <QString>
#include "Collision/CollisionManager.h"


class MovableBlock : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString qmlName READ qmlName CONSTANT)
    Q_PROPERTY(qreal initialX READ initialX WRITE setInitialX NOTIFY initialXChanged)
    Q_PROPERTY(qreal initialY READ initialY WRITE setInitialY NOTIFY initialYChanged)

public:
    explicit MovableBlock(QQuickItem* parent = nullptr)
        : QQuickItem(parent)
    {
    }

    Q_INVOKABLE void Associate(QObject* qml)
    {
        qml_obj = qobject_cast<QQuickItem*>(qml);
    }

    QString qmlName() const { return m_qmlName; }
    qreal initialX() const { return m_initialX; }
    qreal initialY() const { return m_initialY; }

    Q_INVOKABLE void ReleasedMouse()
    {
        if (QQuickItem const* collidedAnchor = CollisionManager::instance()->checkCollision(qml_obj))
        {
            // Align to the collided anchor's position
            qml_obj->setX(collidedAnchor->property("x").toReal());
            qml_obj->setY(collidedAnchor->property("y").toReal());
        }
        else
        {
            // Set the last position if anchor not found
            qml_obj->setX(m_initialX);
            qml_obj->setY(m_initialY);
        }
    }

    Q_INVOKABLE void PressedMouse()
    {
        m_initialX = qml_obj->x();
        m_initialY = qml_obj->y();
    }

    QQuickItem* qml_obj;

private:
    const QString m_qmlName = QString("MovableBlock.qml");
    qreal m_initialX = 0;
    qreal m_initialY = 0;
};

#endif // MOVABLEBLOCK_H
