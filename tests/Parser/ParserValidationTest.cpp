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
    std::vector<std::unique_ptr<Statement>> statements = parser.parse();

    // then
    std::vector<std::unique_ptr<Statement>> expectedStatements;

    // 1. Var - 'var a = 1;'
    expectedStatements.emplace_back(
        new VarStatement(
            Token(TokenType::IDENTIFIER, "a", "", 1),
            new LiteralInt(1)));

    // 2. Expression - 'a = 2;'
    expectedStatements.emplace_back(
        new ExpressionStatement(
            new Assign(
                Token(TokenType::IDENTIFIER, "a", "", 1),
                new LiteralInt(2)
            )));

    ASSERT_EQ(statements.size(), expectedStatements.size());
    for (int i = 0; i < statements.size(); i++)
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
    std::vector<std::unique_ptr<Statement>> statements = parser.parse();

    // then
    std::vector<std::unique_ptr<Statement>> expectedStatements;

    // 1. Var - 'var a = 1 + ( 2 / 3 );'
    expectedStatements.emplace_back(
        new VarStatement(
            Token(TokenType::IDENTIFIER, "a", "", 1),
            new Binary(
                new LiteralInt(1),
                Token(TokenType::PLUS, "+", "", 1),
                new Grouping(
                    new Binary(
                        new LiteralInt(2),
                        Token(TokenType::SLASH, "/", "", 1),
                        new LiteralInt(3)
                    )
                )
            )
        )
    );

    ASSERT_EQ(statements.size(), expectedStatements.size());
    for (int i = 0; i < statements.size(); i++)
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
    std::vector<std::unique_ptr<Statement>> statements = parser.parse();

    // then
    std::vector<Statement*> blockStatements;

    // 1.1 Var - 'var a = 1;'
    blockStatements.push_back(
        new VarStatement(
            Token(TokenType::IDENTIFIER, "a", "", 1),
            new LiteralInt(1)
        )
    );

    // 1.2 Return - 'return a;'
    blockStatements.push_back(
        new ReturnStatement(
            Token(TokenType::RETURN, "return", "", 1),
            new Variable(
                Token(TokenType::IDENTIFIER, "a", "", 1)
            )
        )
    );

    // Encapsulate the block's statements
    auto expectedBlock = std::make_unique<BlockStatement>(blockStatements);

    ASSERT_EQ(statements.size(), 1);
    ASSERT_TRUE(*statements[0] == *expectedBlock);
}

TEST(ParserValidation, IsParserWhileandIfWorkingCorrectly)
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
    std::vector<std::unique_ptr<Statement>> statements = parser.parse();

    // then
    std::vector<std::unique_ptr<Statement>> expectedStatements;

    // 1. Var - 'var a = 0;'
    expectedStatements.emplace_back(
        new VarStatement(
            Token(TokenType::IDENTIFIER, "a", "", 1),
            new LiteralInt(0)
        )
    );

    // 2. While - 'while ( a > 9 ) { ... }'
    {
        // While condition
        auto whileCondition = new Binary(
            new Variable(Token(TokenType::IDENTIFIER, "a", "", 2)),
            Token(TokenType::GREATER, ">", "", 2),
            new LiteralInt(9)
        );

        // While body statements
        std::vector<Statement*> whileBodyStatements;

        // 2.1 a = a + 1;
        whileBodyStatements.push_back(
            new ExpressionStatement(
                new Assign(
                    Token(TokenType::IDENTIFIER, "a", "", 4),
                    new Binary(
                        new Variable(Token(TokenType::IDENTIFIER, "a", "", 4)),
                        Token(TokenType::PLUS, "+", "", 4),
                        new LiteralInt(1)
                    )
                )
            )
        );

        // 2.2 If - 'if ( a == 3 ) { ... }'
        {
            // If condition
            auto ifCondition = new Binary(
                new Variable(Token(TokenType::IDENTIFIER, "a", "", 5)),
                Token(TokenType::EQUAL_EQUAL, "==", "", 5),
                new LiteralInt(3)
            );

            // If body statements
            std::vector<Statement*> ifBodyStatements;

            // 2.2.1 a = a + 6;
            ifBodyStatements.push_back(
                new ExpressionStatement(
                    new Assign(
                        Token(TokenType::IDENTIFIER, "a", "", 7),
                        new Binary(
                            new Variable(Token(TokenType::IDENTIFIER, "a", "", 7)),
                            Token(TokenType::PLUS, "+", "", 7),
                            new LiteralInt(7)
                        )
                    )
                )
            );

            // Create IfStatement
            auto ifThenBranch = new BlockStatement(ifBodyStatements);
            whileBodyStatements.push_back(
                new IfStatement(
                    ifCondition,
                    ifThenBranch,
                    nullptr // No else branch
                )
            );
        }

        // Create WhileStatement
        expectedStatements.emplace_back(
            new WhileStatement(
                whileCondition,
                new BlockStatement(whileBodyStatements)
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
    std::vector<std::unique_ptr<Statement>> statements = parser.parse();

    // then
    std::vector<std::unique_ptr<Statement>> expectedStatements;

    // 1. Print - 'print(1);'
    expectedStatements.emplace_back(new PrintStatement(new Grouping(new LiteralInt(1))));

    ASSERT_EQ(statements.size(), expectedStatements.size());
    for (size_t i = 0; i < statements.size(); i++)
    {
        ASSERT_TRUE(*statements[i] == *expectedStatements[i]);
    }
}

TEST(ParserValidation, AreParsingFunctionsWorkingCorrectly)
{
    // given
    const std::string input = R"(def main() {
                                    var a = 1;
                                    return a;
                                 })";
    Scanner scanner;
    const std::vector<Token> tokens = scanner.scan(input);
    Parser parser(tokens);

    // when
    std::vector<std::unique_ptr<Statement>> statements = parser.parse();

    // then
    std::vector<std::unique_ptr<Statement>> expectedStatements;

    // 1. Function - 'def main() { ... }'
    {
        Token functionName(TokenType::IDENTIFIER, "main", "", 1);
        std::vector<Token> functionParams;
        std::vector<Statement*> functionBody;

        // 1.1 Var - 'var a = 1;'
        functionBody.push_back(
            new VarStatement(
                Token(TokenType::IDENTIFIER, "a", "", 2),
                new LiteralInt(1)
            )
        );

        // 1.2 Return - 'return a;'
        functionBody.push_back(
            new ReturnStatement(
                Token(TokenType::RETURN, "return", "", 3),
                new Variable(
                    Token(TokenType::IDENTIFIER, "a", "", 3)
                )
            )
        );

        // Final function statement
        expectedStatements.emplace_back(
            new FunctionStatement(
                functionName,
                functionParams,
                functionBody
            )
        );
    }

    ASSERT_EQ(statements.size(), expectedStatements.size());
    for (size_t i = 0; i < statements.size(); i++)
    {
        ASSERT_TRUE(*statements[i] == *expectedStatements[i]);
    }
}
