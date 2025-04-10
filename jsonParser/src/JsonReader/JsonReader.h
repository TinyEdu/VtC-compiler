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
    std::map<QString, Handler> functionMap;

    static std::shared_ptr<Block> extract(QJsonValue* block);
    static std::shared_ptr<Block> Break(QJsonValue* block);
    static std::shared_ptr<Block> Call(QJsonValue* block);
    static std::shared_ptr<Block> CreateVarBySignal(QJsonValue* block);
    static std::shared_ptr<Block> CreateVarByValue(QJsonValue* block);
    static std::shared_ptr<Block> End(QJsonValue* block);
    static std::shared_ptr<Block> ForLoop(QJsonValue* block);
    static std::shared_ptr<Block> GetVar(QJsonValue* block);
    static std::shared_ptr<Block> If(QJsonValue* block);
    static std::shared_ptr<Block> Listen(QJsonValue* block);
    static std::shared_ptr<Block> PrintBySignal(QJsonValue* block);
    static std::shared_ptr<Block> PrintByValue(QJsonValue* block);
    static std::shared_ptr<Block> SetVarBySignal(QJsonValue* block);
    static std::shared_ptr<Block> Skip(QJsonValue* block);
    static std::shared_ptr<Block> Start(QJsonValue* block);
    static std::shared_ptr<Block> Value(QJsonValue* block);
    static std::shared_ptr<Block> While(QJsonValue* block);
    static std::shared_ptr<Block> BinaryOp(QJsonValue* block);
    static std::shared_ptr<Block> UnaryOp(QJsonValue* block);
};

#endif //JSONREADER_H
