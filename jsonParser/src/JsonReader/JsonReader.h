#ifndef JSONREADER_H
#define JSONREADER_H

#include <QJsonObject>
#include <vector>

#include "../vo/Block.h"
#include "../vo/Connection.h"

class JsonReader {
public:
    JsonReader();

    static JsonReader* Instance()
    {
        if(instance == nullptr)
        {
            instance = new JsonReader();
        }
        return instance;
    }

    QJsonObject readJson(const std::string& input);

    std::vector<std::shared_ptr<Block>> parseBlocksFromJson(const QJsonObject& json);
    std::vector<Connection> parseConnectionsFromJson(const QJsonObject& json);

private:
    static JsonReader* instance;

    using Handler = std::function<std::shared_ptr<Block>(QJsonValue*)>;
    std::map<std::string, Handler> functionMap;

    std::shared_ptr<Block> extract(QJsonValue* block);

    static std::shared_ptr<Block> extractBreak(QJsonValue* value);
    static std::shared_ptr<Block> extractCall(QJsonValue* value);
    static std::shared_ptr<Block> extractCreateVarBySignal(QJsonValue* value);
    static std::shared_ptr<Block> extractCreateVarByValue(QJsonValue* value);
    static std::shared_ptr<Block> extractEnd(QJsonValue* value);
    static std::shared_ptr<Block> extractForLoop(QJsonValue* value);
    static std::shared_ptr<Block> extractGetVar(QJsonValue* value);
    static std::shared_ptr<Block> extractIf(QJsonValue* value);
    static std::shared_ptr<Block> extractListen(QJsonValue* value);
    static std::shared_ptr<Block> extractPrintBySignal(QJsonValue* value);
    static std::shared_ptr<Block> extractPrintByValue(QJsonValue* value);
    static std::shared_ptr<Block> extractSetVarBySignal(QJsonValue* value);
    static std::shared_ptr<Block> extractSkip(QJsonValue* value);
    static std::shared_ptr<Block> extractStart(QJsonValue* value);
    static std::shared_ptr<Block> extractValue(QJsonValue* value);
    static std::shared_ptr<Block> extractWhile(QJsonValue* value);
    static std::shared_ptr<Block> extractBinaryOp(QJsonValue* value);
    static std::shared_ptr<Block> extractUnaryOp(QJsonValue* value);
};

#endif //JSONREADER_H
