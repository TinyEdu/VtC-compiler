#include "TextParser.h"

#include "Parser/Parser.h"
#include "Scanner/Scanner.h"

std::vector<std::shared_ptr<Statement>> TextParser::parse(const std::string& input)
{
    Scanner scanner;
    const std::vector<Token> tokens = scanner.scan(input);

    Parser parser(tokens);
    const auto statements = parser.parse();

    return statements;
}
