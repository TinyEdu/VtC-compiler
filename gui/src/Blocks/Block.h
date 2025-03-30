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

    std::string name;
    QUuid leftAnchor;
    QUuid rightAnchor;

protected:
    QPointer<QQuickItem> qml_obj;

public:

    virtual QJsonObject toJson() const {
        QJsonObject json;

        json["x"] = x();
        json["y"] = y();

        json["name"] = QString::fromStdString(name);

        json["leftAnchor"] = leftAnchor.toString();
        json["rightAnchor"] = rightAnchor.toString();

        json["blockType"] = getBlockType();

        return json;
    }

    virtual QString getBlockType() const = 0;
};
