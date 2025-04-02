#ifndef CONNECTION_H
#define CONNECTION_H

#include <QJsonObject>
#include <QJsonValue>
#include <QQuickItem>
#include <QPointer>
#include <QUuid>

class Connection {
public:
    virtual ~Connection() = default;

    QUuid from;
    QUuid to;

public:

    QJsonObject toJson() const {
        QJsonObject json;

        json["from"] = from.toString();
        json["to"] = to.toString();

        return json;
    }
};

#endif //CONNECTION_H
