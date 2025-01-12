#ifndef MOVABLEBLOCK_H
#define MOVABLEBLOCK_H

#include <QQuickItem>

class MovableBlock : public QQuickItem {
    Q_OBJECT
    Q_PROPERTY(QString blockName READ blockName WRITE setBlockName NOTIFY blockNameChanged)
    Q_PROPERTY(QQuickItem *boundaryParent READ boundaryParent WRITE setBoundaryParent NOTIFY boundaryParentChanged)

public:
    explicit MovableBlock(QQuickItem *parent = nullptr);

    QString blockName() const;
    void setBlockName(const QString &name);

    QQuickItem *boundaryParent() const;
    void setBoundaryParent(QQuickItem *parent);

    signals:
        void blockNameChanged();
    void boundaryParentChanged();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QString m_blockName;
    QQuickItem *m_boundaryParent = nullptr;
    bool m_dragging = false;
    QPointF m_dragStartPos;
};

#endif // MOVABLEBLOCK_H
