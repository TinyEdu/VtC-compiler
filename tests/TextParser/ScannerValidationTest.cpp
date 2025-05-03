#include <gtest/gtest.h>
#include "TextScanner.h"

TEST(ScannerValidation, IsSingleCharacterTokenWorkingCorrectly)
{
    // given
    const std::string input = "+){.},-(;/***";

    const std::vector expectedOutput = {
        Token(TokenType::PLUS, "+", "", 1),
        Token(TokenType::RIGHT_PAREN, ")", "", 1),
        Token(TokenType::LEFT_BRACE, "{", "", 1),
        Token(TokenType::DOT, ".", "", 1),
        Token(TokenType::RIGHT_BRACE, "}", "", 1),
        Token(TokenType::COMMA, ",", "", 1),
        Token(TokenType::MINUS, "-", "", 1),
        Token(TokenType::LEFT_PAREN, "(", "", 1),
        Token(TokenType::SEMICOLON, ";", "", 1),
        Token(TokenType::SLASH, "/", "", 1),
        Token(TokenType::STAR, "*", "", 1),
        Token(TokenType::STAR, "*", "", 1),
        Token(TokenType::STAR, "*", "", 1),
        Token(TokenType::END_OF_FILE, "", "", 1),
    };

    // when
    TextScanner scanner;
    const std::vector<Token> output = scanner.scan(input);

    // then
    EXPECT_EQ(output.size(), input.size() + 1);
    EXPECT_EQ(output, expectedOutput);
}

TEST(ScannerValidation, IsNewLineAndCommentsAndBlankspacesWorkingCorrecltly)
{
    // given
    const std::string input = "// Here is a comment\n \t/                      /";

    const std::vector expectedOutput = {
        Token(TokenType::SLASH, "/", "", 2),
        Token(TokenType::SLASH, "/", "", 2),
        Token(TokenType::END_OF_FILE, "", "", 2),
    };

    // when
    TextScanner scanner;
    const std::vector<Token> output = scanner.scan(input);

    // then
    EXPECT_EQ(output, expectedOutput);
}

TEST(ScannerValidation, AreMultipleRunsWorkingCorrectly)
{
    // given
    const std::string input = "// Here is a comment\n \t/                      /\n";

    const std::vector expectedOutput = {
        Token(TokenType::SLASH, "/", "", 2),
        Token(TokenType::SLASH, "/", "", 2),
        Token(TokenType::END_OF_FILE, "", "", 3),
    };

    // when
    TextScanner scanner;
    const std::vector<Token> output1 = scanner.scan(input);
    const std::vector<Token> output2 = scanner.scan(input);

    // then
    EXPECT_EQ(output1, expectedOutput);
    EXPECT_EQ(output2, expectedOutput);
}

TEST(ScannerValidation, IsLineCountingCorrect)
{
    // given
    const std::string input = "+\n+\n+\n+\n";

    const std::vector expectedOutput = {
        Token(TokenType::PLUS, "+", "", 1),
        Token(TokenType::PLUS, "+", "", 2),
        Token(TokenType::PLUS, "+", "", 3),
        Token(TokenType::PLUS, "+", "", 4),
        Token(TokenType::END_OF_FILE, "", "", 5)
    };

    // when
    TextScanner scanner;
    const std::vector<Token> output = scanner.scan(input);

    // then
    EXPECT_EQ(output, expectedOutput);
}

TEST(ScannerValidation, IsDoubleCharacterTokenWorkingCorrectly)
{
    // given
    const std::string input = "<= +> >= != ==";

    const std::vector expectedOutput = {
        Token(TokenType::LESS_EQUAL, "<=", "", 1),
        Token(TokenType::PLUS, "+", "", 1),
        Token(TokenType::GREATER, ">", "", 1),
        Token(TokenType::GREATER_EQUAL, ">=", "", 1),
        Token(TokenType::BANG_EQUAL, "!=", "", 1),
        Token(TokenType::EQUAL_EQUAL, "==", "", 1),
        Token(TokenType::END_OF_FILE, "", "", 1)
    };

    // when
    TextScanner scanner;
    const std::vector<Token> output = scanner.scan(input);

    // then
    EXPECT_EQ(output, expectedOutput);
}

TEST(ScannerValidation, IsHandlingLiteralsCorrect)
{
    // given
    const std::string input = "var variable = \"special string\";";

    const std::vector expectedOutput = {
        Token(TokenType::VAR, "var", "", 1),
        Token(TokenType::IDENTIFIER, "variable", "", 1),
        Token(TokenType::EQUAL, "=", "", 1),
        Token(TokenType::STRING, "\"special string\"", "special string", 1),
        Token(TokenType::SEMICOLON, ";", "", 1),
        Token(TokenType::END_OF_FILE, "", "", 1)
    };

    // when
    TextScanner scanner;
    const std::vector<Token> output = scanner.scan(input);

    // then
    EXPECT_EQ(output, expectedOutput);
}

TEST(ScannerValidation, AreNumbersCorrectlyParsed)
{
    // given
    const std::string input = "123 456.789 0.001 \"000\"";

    const std::vector expectedOutput = {
        Token(TokenType::NUMBER, "123", "123", 1),
        Token(TokenType::NUMBER, "456.789", "456.789", 1),
        Token(TokenType::NUMBER, "0.001", "0.001", 1),
        Token(TokenType::STRING, "\"000\"", "000", 1),
        Token(TokenType::END_OF_FILE, "", "", 1)
    };

    // when
    TextScanner scanner;
    const std::vector<Token> output = scanner.scan(input);

    // then
    EXPECT_EQ(output, expectedOutput);
}
