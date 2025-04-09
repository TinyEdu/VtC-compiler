#ifndef JSONREADER_H
#define JSONREADER_H

#include <QJsonObject>
#include <vector>

#include "../vo/Block.h"
#include "../vo/Connection.h"

class JsonReader {
public:
    static QJsonObject readJson(const std::string& input);

    static std::vector<Block> parseBlocksFromJson(const QJsonObject& json);
    static std::vector<Connection> parseConnectionsFromJson(const QJsonObject& json);
    static void print(const std::vector<Block>& blocks, const std::vector<Connection>& connections);
};

#endif //JSONREADER_H
