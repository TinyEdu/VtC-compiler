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
    const auto result = new Connection();

    QVariant rightAnchor;
    if (QMetaObject::invokeMethod(anchor, "getRightAnchor", Qt::DirectConnection,
        Q_RETURN_ARG(QVariant, rightAnchor))) {

        QQuickItem* anchor = rightAnchor.value<QQuickItem*>();
        result->from = readUuidProperty(anchor, "anchorId");
    }

    QVariant leftAnchor;
    if (QMetaObject::invokeMethod(anchor, "getLeftAnchor", Qt::DirectConnection,
        Q_RETURN_ARG(QVariant, leftAnchor))) {

        QQuickItem* anchor = leftAnchor.value<QQuickItem*>();
        result->to = anchor ? readUuidProperty(anchor, "anchorId") : QUuid();
    }

    return result;
}
