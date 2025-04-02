#include "ConnectionReader.h"
#include "ConnectionReaderException.h"
#include "Blocks/Connection.h"

#include <QQmlProperty>

ConnectionReader* ConnectionReader::instance = nullptr;

QUuid ConnectionReader::readUuidProperty(QQuickItem* anchor, QString propertyName)
{
    const QVariant foundPropertyName = anchor->property(propertyName.toStdString().c_str());
    if (!foundPropertyName.isValid()) {
        throw ConnectionReaderException("Property is not set or accessible");
    }

    return QUuid(foundPropertyName.toString());
}

std::string ConnectionReader::readProperty(QQuickItem* anchor, QString propertyName)
{
    const QVariant foundPropertyName = anchor->property(propertyName.toStdString().c_str());
    if (!foundPropertyName.isValid()) {
        throw ConnectionReaderException("Property is not set or accessible");
    }

    return foundPropertyName.toString().toStdString();
}

Connection* ConnectionReader::extract(QQuickItem* anchor)
{
    if (readProperty(anchor, "anchorDirection") != "left")
    {
        return nullptr;
    }

    const auto result = new Connection();
    // Initialize QVariant for the returned value
    QVariant vOtherAnchor;

    // Call the getOtherAnchor method via QMetaObject::invokeMethod
    if (QMetaObject::invokeMethod(anchor, "getOtherAnchor", Qt::DirectConnection, Q_RETURN_ARG(QVariant, vOtherAnchor))) {
        QQuickItem* otherAnchor = vOtherAnchor.value<QQuickItem*>();

        // Read 'anchorId' from both anchor and otherAnchor
        result->from = readUuidProperty(anchor, "anchorId");
        result->to = otherAnchor ? readUuidProperty(otherAnchor, "anchorId") : QUuid();
    }

    if(result->from.isNull() || result->to.isNull()) {
        delete result;
        return nullptr;
    }

    return result;
}
