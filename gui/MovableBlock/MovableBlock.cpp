#include "MovableBlock.h"
#include <QMouseEvent>
#include <QDebug>

MovableBlock::MovableBlock(QQuickItem *parent)
    : QQuickItem(parent) {
    setAcceptedMouseButtons(Qt::LeftButton); // Enable mouse interaction
}

QString MovableBlock::blockName() const {
    return m_blockName;
}

void MovableBlock::setBlockName(const QString &name) {
    if (m_blockName != name) {
        m_blockName = name;
        emit blockNameChanged();
    }
}

QQuickItem *MovableBlock::boundaryParent() const {
    return m_boundaryParent;
}

void MovableBlock::setBoundaryParent(QQuickItem *parent) {
    if (m_boundaryParent != parent) {
        m_boundaryParent = parent;
        emit boundaryParentChanged();
    }
}

void MovableBlock::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_dragging = true;
        m_dragStartPos = event->pos();
    }
    QQuickItem::mousePressEvent(event);
}

void MovableBlock::mouseMoveEvent(QMouseEvent *event) {
    if (m_dragging) {
        QPointF newPos = position() + (event->pos() - m_dragStartPos);

        // Enforce boundary constraints
        if (m_boundaryParent) {
            qreal minX = 0, minY = 0;
            qreal maxX = m_boundaryParent->width() - width();
            qreal maxY = m_boundaryParent->height() - height();

            newPos.setX(qBound(minX, newPos.x(), maxX));
            newPos.setY(qBound(minY, newPos.y(), maxY));
        }

        setPosition(newPos); // Update position
    }
    QQuickItem::mouseMoveEvent(event);
}

void MovableBlock::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_dragging = false;
    }
    QQuickItem::mouseReleaseEvent(event);
}
