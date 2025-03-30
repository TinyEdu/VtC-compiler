#ifndef BLOCK_H
#define BLOCK_H

#include <QUuid>

class Block {
public:
    qreal x() const { return qml_obj ? qml_obj->x() : -1; }
    qreal y() const { return qml_obj ? qml_obj->y() : -1; }

    std::string name;

    QUuid leftAnchor;
    QUuid rightAnchor;

private:
    QPointer<QQuickItem> qml_obj;
};

#endif //BLOCK_H