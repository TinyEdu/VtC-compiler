#include <gtest/gtest.h>
#include "Scanner/Scanner.h"

TEST(ScannerValidation, IsSingleCharacterTokenWorkingCorrectly) {
    using enum TokenType;
    // given
    const std::string input = "+){.},-(;/***";

    const std::vector<Token> expectedOutput = {
        Token(PLUS, "+", "", 1),
        Token(RIGHT_PAREN, ")", "", 1),
        Token(LEFT_BRACE, "{", "", 1),
        Token(DOT, ".", "", 1),
        Token(RIGHT_BRACE, "}", "", 1),
        Token(COMMA, ",", "", 1),
        Token(MINUS, "-", "", 1),
        Token(LEFT_PAREN, "(", "", 1),
        Token(SEMICOLON, ";", "", 1),
        Token(SLASH, "/", "", 1),
        Token(STAR, "*", "", 1),
        Token(STAR, "*", "", 1),
        Token(STAR, "*", "", 1),
        Token(END_OF_FILE, "", "", 1),
    };

    // when
    Scanner scanner;
    const std::vector<Token> output = scanner.scanTokens(input);

    // then
    EXPECT_EQ(output.size(), input.size() + 1);
    EXPECT_EQ(output, expectedOutput);
}

TEST(ScannerValidation, IsNewLineAndCommentsAndBlankspacesWorkingCorrecltly) {
    using enum TokenType;
    // given
    const std::string input = "// Here is a comment\n \t/                      /";

    const std::vector expectedOutput = {
    Token(SLASH, "/", "", 2),
    Token(SLASH, "/", "", 2),
        Token(END_OF_FILE, "", "", 2),
    };

    // when
    Scanner scanner;
    const std::vector<Token> output = scanner.scanTokens(input);

    // then
    EXPECT_EQ(output, expectedOutput);
}

TEST(ScannerValidation, AreMultipleRunsWorkingCorrectly) {
    using enum TokenType;
    // given
    const std::string input = "// Here is a comment\n \t/                      /\n";

    const std::vector expectedOutput = {
        Token(SLASH, "/", "", 2),
        Token(SLASH, "/", "", 2),
            Token(END_OF_FILE, "", "", 3),
        };

    // when
    Scanner scanner;
    const std::vector<Token> output1 = scanner.scanTokens(input);
    const std::vector<Token> output2 = scanner.scanTokens(input);

    // then
    EXPECT_EQ(output1, expectedOutput);
    EXPECT_EQ(output2, expectedOutput);
}

TEST(ScannerValidation, IsLineCountingCorrect) {
    using enum TokenType;
    // given
    const std::string input = "+\n+\n+\n+\n";

    const std::vector expectedOutput = {
        Token(PLUS, "+", "", 1),
        Token(PLUS, "+", "", 2),
        Token(PLUS, "+", "", 3),
        Token(PLUS, "+", "", 4),
        Token(END_OF_FILE, "", "", 5)
        };

    // when
    Scanner scanner;
    const std::vector<Token> output = scanner.scanTokens(input);

    // then
    EXPECT_EQ(output, expectedOutput);
}

TEST(ScannerValidation, IsDoubleCharacterTokenWorkingCorrectly) {
    using enum TokenType;
    // given
    const std::string input = "<= +> >= != ==";

    const std::vector expectedOutput = {
        Token(LESS_EQUAL, "<=", "", 1),
        Token(PLUS, "+", "", 1),
        Token(GREATER, ">", "", 1),
        Token(GREATER_EQUAL, ">=", "", 1),
        Token(BANG_EQUAL, "!=", "", 1),
        Token(EQUAL_EQUAL, "==", "", 1),
        Token(END_OF_FILE, "", "", 1)
    };

    // when
    Scanner scanner;
    const std::vector<Token> output = scanner.scanTokens(input);

    // then
    EXPECT_EQ(output, expectedOutput);
}

TEST(ScannerValidation, IsHandlingLiteralsCorrect) {
    using enum TokenType;
    // given
    const std::string input = "var variable = \"special string\";";

    const std::vector expectedOutput = {
        Token(VAR, "var", "", 1),
        Token(IDENTIFIER, "variable", "", 1),
        Token(EQUAL, "=", "", 1),
        Token(STRING, "\"special string\"", "special string", 1),
        Token(SEMICOLON, ";", "", 1),
        Token(END_OF_FILE, "", "", 1)
    };

    // when
    Scanner scanner;
    const std::vector<Token> output = scanner.scanTokens(input);

    // then
    EXPECT_EQ(output, expectedOutput);
}