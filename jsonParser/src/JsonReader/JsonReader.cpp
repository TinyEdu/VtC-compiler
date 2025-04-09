#include "JsonReader.h"

#include <QJsonArray>
#include <qjsondocument.h>

QJsonObject JsonReader::readJson(const std::string& input) {
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(QString::fromStdString(input).toUtf8(), &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "JSON parse error:" << parseError.errorString();
        return QJsonObject{};
    }

    if (!doc.isObject()) {
        qWarning() << "JSON root is not an object.";
        return QJsonObject{};
    }

    return doc.object();
}


std::vector<Block> JsonReader::parseBlocksFromJson(const QJsonObject& json) {
    std::vector<Block> blocks;
    QJsonArray blockArray = json["Blocks"].toArray();

    for (const QJsonValue& val : blockArray) {
        QJsonObject obj = val.toObject();
        Block b;

        b.blockType = obj["blockType"].toString().toStdString();
        b.leftAnchor = obj["leftAnchor"].toString().toStdString();
        b.rightAnchor = obj["rightAnchor"].toString().toStdString();
        b.passingAnchor = obj.contains("passingAnchor") ? obj["passingAnchor"].toString().toStdString() : "";
        b.value = obj.contains("value") ? obj["value"].toString().toStdString() : "";
        b.variable = obj.contains("variable") ? obj["variable"].toString().toStdString() : "";

        blocks.push_back(b);
    }

    return blocks;
}

std::vector<Connection> JsonReader::parseConnectionsFromJson(const QJsonObject& json) {
    std::vector<Connection> connections;
    QJsonArray connArray = json["Connections"].toArray();

    for (const QJsonValue& val : connArray) {
        QJsonObject obj = val.toObject();
        Connection c;

        c.from = QUuid(obj["from"].toString());
        c.to = QUuid(obj["to"].toString());

        connections.push_back(c);
    }

    return connections;
}

void JsonReader::print(const std::vector<Block>& blocks, const std::vector<Connection>& connections)
{
    qDebug() << "Blocks (" << blocks.size() << "):";
    for (const auto& block : blocks) {
        qDebug().noquote() << "  Block:"
                           << "\n    Type:         " << QString::fromStdString(block.blockType)
                           << "\n    Left Anchor:  " << QString::fromStdString(block.leftAnchor)
                           << "\n    Right Anchor: " << QString::fromStdString(block.rightAnchor)
                           << "\n    PassingAnchor:" << QString::fromStdString(block.passingAnchor)
                           << "\n    Value:        " << QString::fromStdString(block.value)
                           << "\n    Variable:     " << QString::fromStdString(block.variable);
    }

    qDebug() << "\nConnections (" << connections.size() << "):";
    for (const auto& conn : connections) {
        qDebug() << "  From:" << conn.from.toString()
                 << "  To:" << conn.to.toString();
    }
}
