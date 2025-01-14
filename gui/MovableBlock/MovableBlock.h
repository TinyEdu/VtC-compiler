#ifndef MOVABLEBLOCK_H
#define MOVABLEBLOCK_H

#include <QQuickItem>
#include <QString>
#include "Collision/CollisionManager.h"


class MovableBlock : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString qmlName READ qmlName CONSTANT)

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

    Q_INVOKABLE void ReleasedMouse()
    {
        if (QQuickItem* collidedAnchor = CollisionManager::instance()->checkCollision(qml_obj))
        {
            // Get the position of the anchor in the root coordinate space
            QPointF anchorPositionInRoot = collidedAnchor->mapToItem(nullptr, 0, 0);

            // Map the root position back to qml_obj's parent coordinate space
            QPointF alignedPosition = qml_obj->parentItem()->mapFromItem(
                nullptr, anchorPositionInRoot.x(), anchorPositionInRoot.y());

            // Align qml_obj to the transformed position
            qml_obj->setX(alignedPosition.x());
            qml_obj->setY(alignedPosition.y());
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
