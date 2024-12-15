#include "gtest/gtest.h"
#include "Parser/Parser.h"
#include "Scanner/Scanner.h"

TEST(ParserValidation, tts) {
    // given
    const std::string input = "var a = 1; a = 2;";

    // when
    Scanner scanner;
    const std::vector<Token> tokens = scanner.scan(input);
    Parser parser(tokens);
    std::vector<Statement*> statements = parser.parse();

    // then

}