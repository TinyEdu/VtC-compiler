#ifndef BLOCK_H
#define BLOCK_H

#include <QJsonObject>
#include <QJsonValue>
#include <QQuickItem>
#include <QPointer>
#include <QUuid>

#define DEFINE_BLOCK_TYPE(ClassName) QString getBlockType() const override { return #ClassName; }

class Block {
public:
    virtual ~Block() = default;

    qreal x() const { return qml_obj ? qml_obj->x() : -1; }
    qreal y() const { return qml_obj ? qml_obj->y() : -1; }

    void setQmlObj(QQuickItem* obj) { qml_obj = obj; }

    QString name;
    QUuid leftAnchor;
    QUuid rightAnchor;

protected:
    QPointer<QQuickItem> qml_obj;

public:

    virtual QJsonObject toJson() const {
        QJsonObject json;

        json["x"] = x();
        json["y"] = y();

        json["name"] = name;

        json["leftAnchor"] = leftAnchor.toString();
        json["rightAnchor"] = rightAnchor.toString();

        json["blockType"] = getBlockType();

        return json;
    }

    virtual QString getBlockType() const = 0;
};

#endif //BLOCK_H