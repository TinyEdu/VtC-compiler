#include "gtest/gtest.h"
#include "Parser/Parser.h"
#include "Scanner/Scanner.h"
#include "Expressions/ExpressionsWorld.h"
#include "Statements/StatementsWorld.h"

TEST(ParserValidation, IsParsingVariableAndSimpleExpressionWorkingCorrectly)
{
    // given
    const std::string input = "var a = 1; a = 2;";

    // when
    Scanner scanner;
    const std::vector<Token> tokens = scanner.scan(input);
    Parser parser(tokens);
    const std::vector<std::shared_ptr<Statement>> statements = parser.parse();

    // then
    std::vector<std::shared_ptr<Statement>> expectedStatements;

    // 1. Var - 'var a = 1;'
    expectedStatements.emplace_back(
        std::make_shared<VarStatement>(
            Token(TokenType::IDENTIFIER, "a", "", 1),
            std::make_shared<LiteralInt>(1)));

    // 2. Expression - 'a = 2;'
    expectedStatements.emplace_back(
        std::make_shared<ExpressionStatement>(
            std::make_shared<Assign>(
                Token(TokenType::IDENTIFIER, "a", "", 1),
                std::make_shared<LiteralInt>(2)
            )));

    ASSERT_EQ(statements.size(), expectedStatements.size());
    for (size_t i = 0; i < statements.size(); i++)
    {
        ASSERT_TRUE(*expectedStatements[i] == *statements[i]);
    }
}

TEST(ParserValidation, IsParsingComplexExpressionWorkingCorrectly)
{
    // given
    const std::string input = "var a = 1 + ( 2 / 3 );";

    // when
    Scanner scanner;
    const std::vector<Token> tokens = scanner.scan(input);
    Parser parser(tokens);
    const std::vector<std::shared_ptr<Statement>> statements = parser.parse();

    // then
    std::vector<std::shared_ptr<Statement>> expectedStatements;

    // 1. Var - 'var a = 1 + ( 2 / 3 );'
    expectedStatements.emplace_back(
        std::make_shared<VarStatement>(
            Token(TokenType::IDENTIFIER, "a", "", 1),
            std::make_shared<Binary>(
                std::make_shared<LiteralInt>(1),
                Token(TokenType::PLUS, "+", "", 1),
                std::make_shared<Grouping>(
                    std::make_shared<Binary>(
                        std::make_shared<LiteralInt>(2),
                        Token(TokenType::SLASH, "/", "", 1),
                        std::make_shared<LiteralInt>(3)
                    )
                )
            )
        )
    );

    ASSERT_EQ(statements.size(), expectedStatements.size());
    for (size_t i = 0; i < statements.size(); i++)
    {
        ASSERT_TRUE(*expectedStatements[i] == *statements[i]);
    }
}

TEST(ParserValidation, IsParsingBlockAndReturnWorkingCorrectly)
{
    // given
    const std::string input = "{ var a = 1; return a; }";
    Scanner scanner;
    const std::vector<Token> tokens = scanner.scan(input);
    Parser parser(tokens);

    // when
    const std::vector<std::shared_ptr<Statement>> statements = parser.parse();

    // then
    std::vector<std::shared_ptr<Statement>> blockStatements;

    // 1.1 Var - 'var a = 1;'
    blockStatements.push_back(
        std::make_shared<VarStatement>(
            Token(TokenType::IDENTIFIER, "a", "", 1),
            std::make_shared<LiteralInt>(1)
        )
    );

    // 1.2 Return - 'return a;'
    blockStatements.push_back(
        std::make_shared<ReturnStatement>(
            Token(TokenType::RETURN, "return", "", 1),
            std::make_shared<Variable>(
                Token(TokenType::IDENTIFIER, "a", "", 1)
            )
        )
    );

    auto expectedBlock = std::make_shared<BlockStatement>(blockStatements);

    ASSERT_EQ(statements.size(), 1);
    ASSERT_TRUE(*statements[0] == *expectedBlock);
}

TEST(ParserValidation, IsParserWhileAndIfWorkingCorrectly)
{
    // given
    const std::string input = R"(var a = 0;
                                 while ( a > 9 )
                                 {
                                     a = a + 1;
                                     if ( a == 3 )
                                     {
                                         a = a + 6;
                                     }
                                 })";
    Scanner scanner;
    const std::vector<Token> tokens = scanner.scan(input);
    Parser parser(tokens);

    // when
    const std::vector<std::shared_ptr<Statement>> statements = parser.parse();

    // then
    std::vector<std::shared_ptr<Statement>> expectedStatements;

    // 1. Var - 'var a = 0;'
    expectedStatements.emplace_back(
        std::make_shared<VarStatement>(
            Token(TokenType::IDENTIFIER, "a", "", 1),
            std::make_shared<LiteralInt>(0)
        )
    );

    // 2. While - 'while ( a > 9 ) { ... }'
    {
        auto whileCondition = std::make_shared<Binary>(
            std::make_shared<Variable>(Token(TokenType::IDENTIFIER, "a", "", 2)),
            Token(TokenType::GREATER, ">", "", 2),
            std::make_shared<LiteralInt>(9)
        );

        std::vector<std::shared_ptr<Statement>> whileBodyStatements;

        // 2.1 a = a + 1;
        whileBodyStatements.push_back(
            std::make_shared<ExpressionStatement>(
                std::make_shared<Assign>(
                    Token(TokenType::IDENTIFIER, "a", "", 4),
                    std::make_shared<Binary>(
                        std::make_shared<Variable>(Token(TokenType::IDENTIFIER, "a", "", 4)),
                        Token(TokenType::PLUS, "+", "", 4),
                        std::make_shared<LiteralInt>(1)
                    )
                )
            )
        );

        // 2.2 If - 'if ( a == 3 ) { ... }'
        auto ifCondition = std::make_shared<Binary>(
            std::make_shared<Variable>(Token(TokenType::IDENTIFIER, "a", "", 5)),
            Token(TokenType::EQUAL_EQUAL, "==", "", 5),
            std::make_shared<LiteralInt>(3)
        );

        std::vector<std::shared_ptr<Statement>> ifBodyStatements;
        ifBodyStatements.push_back(
            std::make_shared<ExpressionStatement>(
                std::make_shared<Assign>(
                    Token(TokenType::IDENTIFIER, "a", "", 7),
                    std::make_shared<Binary>(
                        std::make_shared<Variable>(Token(TokenType::IDENTIFIER, "a", "", 7)),
                        Token(TokenType::PLUS, "+", "", 7),
                        std::make_shared<LiteralInt>(6)
                    )
                )
            )
        );

        auto ifThenBranch = std::make_shared<BlockStatement>(ifBodyStatements);
        whileBodyStatements.push_back(
            std::make_shared<IfStatement>(ifCondition, ifThenBranch, nullptr)
        );

        expectedStatements.emplace_back(
            std::make_shared<WhileStatement>(
                whileCondition,
                std::make_shared<BlockStatement>(whileBodyStatements)
            )
        );
    }

    ASSERT_EQ(statements.size(), expectedStatements.size());
    for (size_t i = 0; i < statements.size(); i++)
    {
        ASSERT_TRUE(*statements[i] == *expectedStatements[i]);
    }
}

TEST(ParserValidation, IsParserPrintWorkingCorrectly)
{
    // given
    const std::string input = "print(1);";
    Scanner scanner;
    const std::vector<Token> tokens = scanner.scan(input);
    Parser parser(tokens);

    // when
    const std::vector<std::shared_ptr<Statement>> statements = parser.parse();

    // then
    std::vector<std::shared_ptr<Statement>> expectedStatements;

    // 1. Print - 'print(1);'
    expectedStatements.emplace_back(
        std::make_shared<PrintStatement>(
            std::make_shared<Grouping>(std::make_shared<LiteralInt>(1))
        )
    );

    ASSERT_EQ(statements.size(), expectedStatements.size());
    for (size_t i = 0; i < statements.size(); i++)
    {
        ASSERT_TRUE(*statements[i] == *expectedStatements[i]);
    }
}
