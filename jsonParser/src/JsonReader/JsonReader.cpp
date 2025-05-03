#include "JsonReader.h"

#include <QJsonArray>
#include <qjsondocument.h>

JsonReader::JsonReader()
{
    functionMap["Break"] = &JsonReader::extractBreak;
    functionMap["Call"] = &JsonReader::extractCall;
    functionMap["CreateVarBySignal"] = &JsonReader::extractCreateVarBySignal;
    functionMap["CreateVarByValue"] = &JsonReader::extractCreateVarByValue;
    functionMap["End"] = &JsonReader::extractEnd;
    functionMap["ForLoop"] = &JsonReader::extractForLoop;
    functionMap["GetVar"] = &JsonReader::extractGetVar;
    functionMap["If"] = &JsonReader::extractIf;
    functionMap["Listen"] = &JsonReader::extractListen;
    functionMap["PrintBySignal"] = &JsonReader::extractPrintBySignal;
    functionMap["PrintByValue"] = &JsonReader::extractPrintByValue;
    functionMap["SetVarBySignal"] = &JsonReader::extractSetVarBySignal;
    functionMap["SetVarByValue"] = &JsonReader::extractSetVarBySignal;
    functionMap["Skip"] = &JsonReader::extractSkip;
    functionMap["Start"] = &JsonReader::extractStart;
    functionMap["Value"] = &JsonReader::extractValue;
    functionMap["While"] = &JsonReader::extractWhile;
    functionMap["BinaryOp"] = &JsonReader::extractBinaryOp;
    functionMap["UnaryOp"] = &JsonReader::extractUnaryOp;
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

    return blocks;
}

std::vector<Connection> JsonReader::parseConnectionsFromJson(const QJsonObject& json) {
    std::vector<Connection> connections;
    QJsonArray connArray = json["Connections"].toArray();

    for (const QJsonValue& val : connArray) {
        QJsonObject obj = val.toObject();
        Connection c;

        c.from = obj["from"].toString().toStdString();
        c.to = obj["to"].toString().toStdString();

        connections.push_back(c);
    }

    return connections;
}

std::shared_ptr<Block> JsonReader::extract(QJsonValue* block)
{
    const std::string blockName = block->toObject()["blockType"].toString().toStdString();

    const auto it = functionMap.find(blockName);
    if (it == functionMap.end())
    {
        throw std::invalid_argument("Function not found: " + blockName);
    }

    return it->second(block);
}

std::shared_ptr<Block> JsonReader::extractBreak(QJsonValue* value)
{
    auto block = std::make_shared<Break>();
    block->fromJson(*value);

    return block;
}

std::shared_ptr<Block> JsonReader::extractCall(QJsonValue* value)
{
    auto block = std::make_shared<Call>();
    block->fromJson(*value);

    return block;
}

std::shared_ptr<Block> JsonReader::extractCreateVarBySignal(QJsonValue* value)
{
    auto block = std::make_shared<CreateVar>();
    block->fromJson(*value);

    return block;
}

std::shared_ptr<Block> JsonReader::extractCreateVarByValue(QJsonValue* value)
{
    auto block = std::make_shared<CreateVar>();
    block->fromJson(*value);

    return block;
}

std::shared_ptr<Block> JsonReader::extractEnd(QJsonValue* value)
{
    auto block = std::make_shared<End>();
    block->fromJson(*value);

    return block;
}

std::shared_ptr<Block> JsonReader::extractForLoop(QJsonValue* value)
{
    auto block = std::make_shared<ForLoop>();
    block->fromJson(*value);

    return block;
}

std::shared_ptr<Block> JsonReader::extractGetVar(QJsonValue* value)
{
    auto block = std::make_shared<GetVar>();
    block->fromJson(*value);

    return block;
}

std::shared_ptr<Block> JsonReader::extractIf(QJsonValue* value)
{
    auto block = std::make_shared<If>();
    block->fromJson(*value);

    return block;
}

std::shared_ptr<Block> JsonReader::extractListen(QJsonValue* value)
{
    auto block = std::make_shared<Listen>();
    block->fromJson(*value);

    return block;
}

std::shared_ptr<Block> JsonReader::extractPrintBySignal(QJsonValue* value)
{
    auto block = std::make_shared<Print>();
    block->fromJson(*value);

    return block;
}

std::shared_ptr<Block> JsonReader::extractPrintByValue(QJsonValue* value)
{
    auto block = std::make_shared<Print>();
    block->fromJson(*value);

    return block;
}

std::shared_ptr<Block> JsonReader::extractSetVarBySignal(QJsonValue* value)
{
    auto block = std::make_shared<SetVar>();
    block->fromJson(*value);

    return block;
}

std::shared_ptr<Block> JsonReader::extractSetVarByValue(QJsonValue* value)
{
    auto block = std::make_shared<SetVar>();
    block->fromJson(*value);

    return block;
}

std::shared_ptr<Block> JsonReader::extractSkip(QJsonValue* value)
{
    auto block = std::make_shared<Skip>();
    block->fromJson(*value);

    return block;
}

std::shared_ptr<Block> JsonReader::extractStart(QJsonValue* value)
{
    auto block = std::make_shared<Start>();
    block->fromJson(*value);

    return block;
}

std::shared_ptr<Block> JsonReader::extractValue(QJsonValue* value)
{
    auto block = std::make_shared<Value>();
    block->fromJson(*value);

    return block;
}

std::shared_ptr<Block> JsonReader::extractWhile(QJsonValue* value)
{
    auto block = std::make_shared<While>();
    block->fromJson(*value);

    return block;
}

std::shared_ptr<Block> JsonReader::extractBinaryOp(QJsonValue* value)
{
    auto block = std::make_shared<BinaryOp>();
    block->fromJson(*value);

    return block;
}

std::shared_ptr<Block> JsonReader::extractUnaryOp(QJsonValue* value)
{
    auto block = std::make_shared<UnaryOp>();
    block->fromJson(*value);

    return block;
}
