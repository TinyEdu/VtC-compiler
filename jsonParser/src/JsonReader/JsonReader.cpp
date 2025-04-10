#include "JsonReader.h"

#include <QJsonArray>
#include <qjsondocument.h>

JsonReader::JsonReader()
{
    functionMap["Break"] = &JsonReader::Break;
    functionMap["Call"] = &JsonReader::Call;
    functionMap["CreateVarBySignal"] = &JsonReader::CreateVarBySignal;
    functionMap["CreateVarByValue"] = &JsonReader::CreateVarByValue;
    functionMap["End"] = &JsonReader::End;
    functionMap["ForLoop"] = &JsonReader::ForLoop;
    functionMap["GetVar"] = &JsonReader::GetVar;
    functionMap["If"] = &JsonReader::If;
    functionMap["Listen"] = &JsonReader::Listen;
    functionMap["PrintBySignal"] = &JsonReader::PrintBySignal;
    functionMap["PrintByValue"] = &JsonReader::PrintByValue;
    functionMap["SetVarBySignal"] = &JsonReader::SetVarBySignal;
    functionMap["Skip"] = &JsonReader::Skip;
    functionMap["Start"] = &JsonReader::Start;
    functionMap["Value"] = &JsonReader::Value;
    functionMap["While"] = &JsonReader::While;
    functionMap["BinaryOp"] = &JsonReader::BinaryOp;
    functionMap["UnaryOp"] = &JsonReader::UnaryOp;
}

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


std::vector<std::shared_ptr<Block>> JsonReader::parseBlocksFromJson(const QJsonObject& json) {
    std::vector<std::shared_ptr<Block>> blocks;
    QJsonArray blockArray = json["Blocks"].toArray();

    for (QJsonValue block : blockArray)
    {
        blocks.push_back(extract(&block));
    }

    return {};
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

std::shared_ptr<Block> JsonReader::extract(QJsonValue* block)
{
    return {};
}

std::shared_ptr<Block> JsonReader::Break(QJsonValue* block)
{
    return {};
}

std::shared_ptr<Block> JsonReader::Call(QJsonValue* block)
{
    return {};
}

std::shared_ptr<Block> JsonReader::CreateVarBySignal(QJsonValue* block)
{
    return {};
}

std::shared_ptr<Block> JsonReader::CreateVarByValue(QJsonValue* block)
{
    return {};
}

std::shared_ptr<Block> JsonReader::End(QJsonValue* block)
{
    return {};
}

std::shared_ptr<Block> JsonReader::ForLoop(QJsonValue* block)
{
    return {};
}

std::shared_ptr<Block> JsonReader::GetVar(QJsonValue* block)
{
    return {};
}

std::shared_ptr<Block> JsonReader::If(QJsonValue* block)
{
    return {};
}

std::shared_ptr<Block> JsonReader::Listen(QJsonValue* block)
{
    return {};
}

std::shared_ptr<Block> JsonReader::PrintBySignal(QJsonValue* block)
{
    return {};
}

std::shared_ptr<Block> JsonReader::PrintByValue(QJsonValue* block)
{
    return {};
}

std::shared_ptr<Block> JsonReader::SetVarBySignal(QJsonValue* block)
{
    return {};
}

std::shared_ptr<Block> JsonReader::Skip(QJsonValue* block)
{
    return {};
}

std::shared_ptr<Block> JsonReader::Start(QJsonValue* block)
{
    return {};
}

std::shared_ptr<Block> JsonReader::Value(QJsonValue* block)
{
    return {};
}

std::shared_ptr<Block> JsonReader::While(QJsonValue* block)
{
    return {};
}

std::shared_ptr<Block> JsonReader::BinaryOp(QJsonValue* block)
{
    return {};
}

std::shared_ptr<Block> JsonReader::UnaryOp(QJsonValue* block)
{
    return {};
}

