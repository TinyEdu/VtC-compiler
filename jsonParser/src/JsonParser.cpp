#include "JsonParser.h"

#include <iostream>

#include "BlockExtractor/BlockExtractor.h"
#include "JsonReader/JsonReader.h"
#include "vo/Block.h"
#include "vo/Connection.h"

#include <QCoreApplication>

std::vector<std::shared_ptr<Statement>> JsonParser::parse(const std::string& input)
{
    std::cout << "Parsing JSON input..." << std::endl;
    std::cout << input << std::endl;
    JsonReader reader;
    QJsonObject json = reader.readJson(input);

    Anchor::clearAnchors();
    std::vector<std::shared_ptr<Block>> blocks = reader.parseBlocksFromJson(json);
    std::vector<Connection> connections = reader.parseConnectionsFromJson(json);
    Anchor::loadConnections(connections);

    BlockExtractor extractor(blocks, connections);
    std::vector<std::shared_ptr<Statement>> result = extractor.buildAST();

    std::cout << "Finished extracting AST." << std::endl;
    return result;
}
