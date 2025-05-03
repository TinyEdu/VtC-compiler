#include "TextParser.h"

#include "TextScanner.h"
#include "Parser/Parser.h"

std::vector<std::shared_ptr<Statement>> TextParser::parse(const std::string& input)
{
    TextScanner scanner;
    const std::vector<Token> tokens = scanner.scan(input);

    Parser parser(tokens);
    const auto statements = parser.parse();

    return statements;
}
