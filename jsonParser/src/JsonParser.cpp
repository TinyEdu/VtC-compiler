#include "JsonParser.h"

#include "BlockExtractor/BlockExtractor.h"
#include "JsonReader/JsonReader.h"
#include "vo/Block.h"
#include "vo/Connection.h"

#include <QCoreApplication>

std::vector<std::shared_ptr<Statement>> JsonParser::parse(const std::string& input)
{
    JsonReader reader;
    QJsonObject json = reader.readJson(input);
    std::vector<std::shared_ptr<Block>> blocks = reader.parseBlocksFromJson(json);
    std::vector<Connection> connections = reader.parseConnectionsFromJson(json);

    BlockExtractor extractor(blocks, connections);
    return extractor.buildAST();
}
