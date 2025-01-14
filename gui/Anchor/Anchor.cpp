#include "Anchor.h"
#include "Collision/CollisionManager.h"

Anchor::Anchor() : m_color(Qt::red) { // Default color is red
    CollisionManager::instance()->registerAnchor(this);
}

QColor Anchor::color() const {
    return m_color;
}

void Anchor::setColor(const QColor &color) {
    if (m_color != color) {
        m_color = color;
        emit colorChanged();
    }
}
