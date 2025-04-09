#include "JsonParser.h"

#include <QCoreApplication>
#include <QJsonDocument>

#include "JsonReader/JsonReader.h"
#include "vo/Block.h"
#include "vo/Connection.h"

std::vector<std::shared_ptr<Statement>> JsonParser::parse(const std::string& input)
{
    QJsonObject json = JsonReader::readJson(input);
    std::vector<Block> blocks = JsonReader::parseBlocksFromJson(json);
    std::vector<Connection> connections = JsonReader::parseConnectionsFromJson(json);

    JsonReader::print(blocks, connections);
    return {};
}
