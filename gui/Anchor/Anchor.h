#ifndef ANCHOR_H
#define ANCHOR_H

#include <QQuickItem>
#include <QColor>

class Anchor : public QQuickItem {
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

public:
    Anchor();
    QColor color() const;
    void setColor(const QColor &color);

    signals:
        void colorChanged();

private:
    QColor m_color;
};

#endif // ANCHOR_H
