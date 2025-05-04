#include <gtest/gtest.h>
#include "JsonParser.h"

#include <filesystem>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <Expressions/Assign.h>
#include <Expressions/Binary.h>
#include <Expressions/Unary.h>
#include <Expressions/Variable.h>
#include <Expressions/Literals/LiteralBool.h>
#include <Expressions/Literals/LiteralInt.h>
#include <Expressions/Literals/LiteralString.h>

#include "Interpreter.h"
#include "Statements/BlockStatement.h"
#include "Statements/ExpressionStatement.h"
#include "Statements/IfStatement.h"
#include "Statements/PrintStatement.h"
#include "Statements/VarStatement.h"
#include "Statements/WhileStatement.h"

#define CAPTURE_STDOUT(outputStream, codeBlock)                             \
{                                                                           \
std::stringstream _captureStream;                                           \
std::streambuf* _originalBuffer = std::cout.rdbuf(_captureStream.rdbuf());  \
codeBlock                                                                   \
std::cout.rdbuf(_originalBuffer);                                           \
outputStream = _captureStream.str();                                        \
}

TEST(InterpreterTest, Print)
{
    // GIVEN
    const std::vector<std::shared_ptr<Statement>> input = {
        std::make_shared<PrintStatement>(std::make_shared<LiteralString>("printing!"))
    };

    // WHEN
    std::string capturedOutput;
    CAPTURE_STDOUT(capturedOutput, {
        Interpreter interpreter;
        interpreter.execute(input);
    });

    // THEN
    std::string expectedOutput = "print: printing!\n";
    ASSERT_EQ(capturedOutput, expectedOutput) << "Captured output does not match expected output";
}

TEST(InterpreterTest, CreateVarAndPrint)
{
    // GIVEN
    const std::vector<std::shared_ptr<Statement>> input = {
        std::make_shared<VarStatement>(
            Token(TokenType::IDENTIFIER, "var", ""),
            std::make_shared<LiteralString>("val")),
        std::make_shared<PrintStatement>(
            std::make_shared<Variable>(Token(TokenType::IDENTIFIER, "var", "")))
    };

    // WHEN
    std::string capturedOutput;
    CAPTURE_STDOUT(capturedOutput, {
        Interpreter interpreter;
        interpreter.execute(input);
    });

    // THEN
    std::string expectedOutput = "print: val\n";
    ASSERT_EQ(capturedOutput, expectedOutput);
}

TEST(InterpreterTest, CreateVarWithBinary)
{
    // GIVEN
    const std::vector<std::shared_ptr<Statement>> input = {
        std::make_shared<VarStatement>(
            Token(TokenType::IDENTIFIER, "var", ""),
            std::make_shared<Binary>(
                std::make_shared<LiteralInt>(99),
                Token(TokenType::PLUS, "add", ""),
                std::make_shared<LiteralInt>(1))),
        std::make_shared<PrintStatement>(
            std::make_shared<Variable>(Token(TokenType::IDENTIFIER, "var", "")))
    };

    // WHEN
    std::string capturedOutput;
    CAPTURE_STDOUT(capturedOutput, {
        Interpreter interpreter;
        interpreter.execute(input);
    });

    // THEN
    std::string expectedOutput = "print: 100\n";
    ASSERT_EQ(capturedOutput, expectedOutput);
}

TEST(InterpreterTest, IfStatementTrueBranch)
{
    // GIVEN
    auto ifCondition = std::make_shared<Binary>(
        std::make_shared<LiteralInt>(100),
        Token(TokenType::GREATER_EQUAL, ">=", ""),
        std::make_shared<LiteralInt>(10));

    std::vector<std::shared_ptr<Statement>> ifBody = {
        std::make_shared<PrintStatement>(std::make_shared<LiteralString>("TRU"))
    };
    std::vector<std::shared_ptr<Statement>> elseBody = {
        std::make_shared<PrintStatement>(std::make_shared<LiteralString>("FLS"))
    };

    const std::vector<std::shared_ptr<Statement>> input = {
        std::make_shared<IfStatement>(
            ifCondition,
            std::make_shared<BlockStatement>(ifBody),
            std::make_shared<BlockStatement>(elseBody))
    };

    // WHEN
    std::string capturedOutput;
    CAPTURE_STDOUT(capturedOutput, {
        Interpreter interpreter;
        interpreter.execute(input);
    });

    // THEN
    std::string expectedOutput = "print: TRU\n";
    ASSERT_EQ(capturedOutput, expectedOutput);
}

TEST(InterpreterTest, SimpleForLoopPrints)
{
    // GIVEN
    auto initializer = std::make_shared<VarStatement>(
        Token(TokenType::IDENTIFIER, "a", ""),
        std::make_shared<LiteralInt>(0));

    auto condition = std::make_shared<Binary>(
        std::make_shared<Variable>(Token(TokenType::IDENTIFIER, "a", "")),
        Token(TokenType::LESS_EQUAL, "<=", ""),
        std::make_shared<LiteralInt>(2));  // keep small for test

    auto increment = std::make_shared<Assign>(
        Token(TokenType::IDENTIFIER, "a", ""),
        std::make_shared<Binary>(
            std::make_shared<Variable>(Token(TokenType::IDENTIFIER, "a", "")),
            Token(TokenType::PLUS, "+", ""),
            std::make_shared<LiteralInt>(1)));

    std::vector<std::shared_ptr<Statement>> body = {
        std::make_shared<PrintStatement>(
            std::make_shared<Variable>(Token(TokenType::IDENTIFIER, "a", ""))),
        std::make_shared<ExpressionStatement>(increment)
    };

    auto whileLoop = std::make_shared<WhileStatement>(
        condition,
        std::make_shared<BlockStatement>(body));

    const std::vector<std::shared_ptr<Statement>> input = {
        initializer,
        whileLoop
    };

    // WHEN
    std::string capturedOutput;
    CAPTURE_STDOUT(capturedOutput, {
        Interpreter interpreter;
        interpreter.execute(input);
    });

    // THEN
    std::string expectedOutput = "print: 0\nprint: 1\nprint: 2\n";
    ASSERT_EQ(capturedOutput, expectedOutput);
}

TEST(InterpreterTest, PrintUninitializedVariable)
{
    // GIVEN
    const std::vector<std::shared_ptr<Statement>> input = {
        std::make_shared<PrintStatement>(
            std::make_shared<Variable>(Token(TokenType::IDENTIFIER, "missingVar", ""))
        )
    };

    // WHEN
    std::string capturedCritical;
    CAPTURE_STDOUT(capturedCritical, {

        Interpreter interpreter;
        interpreter.execute(input);
    });

    // THEN
    const std::string expectedCritical = "Undefined variable 'missingVar'.";
    ASSERT_NE(capturedCritical.find(expectedCritical), std::string::npos) << "Error message does not contain expected substring";
}

TEST(InterpreterTest, WhileLoopFalseConditionSkipsBody)
{
    // GIVEN
    auto condition = std::make_shared<LiteralBool>(false);
    auto body = std::make_shared<BlockStatement>(
        std::vector<std::shared_ptr<Statement>>{
            std::make_shared<PrintStatement>(std::make_shared<LiteralString>("should not print"))
        });

    const std::vector<std::shared_ptr<Statement>> input = {
        std::make_shared<WhileStatement>(condition, body)
    };

    // WHEN
    std::string capturedOutput;
    CAPTURE_STDOUT(capturedOutput, {
        Interpreter interpreter;
        interpreter.execute(input);
    });

    const std::string expectedOutput = "";
    ASSERT_EQ(capturedOutput, expectedOutput) << "Nothing should be printed";
}

TEST(InterpreterTest, IfWithoutElseTrueBranch)
{
    // GIVEN
    auto ifCondition = std::make_shared<LiteralBool>(true);
    auto ifBody = std::make_shared<BlockStatement>(
        std::vector<std::shared_ptr<Statement>>{
            std::make_shared<PrintStatement>(std::make_shared<LiteralString>("yes"))
        });

    const std::vector<std::shared_ptr<Statement>> input = {
        std::make_shared<IfStatement>(ifCondition, ifBody, nullptr)
    };

    // WHEN
    std::string capturedOutput;
    CAPTURE_STDOUT(capturedOutput, {
        Interpreter interpreter;
        interpreter.execute(input);
    });

    // THEN
    const std::string expectedOutput = "print: yes\n";
    ASSERT_EQ(capturedOutput, expectedOutput);
}

TEST(InterpreterTest, ReassignVariableInLoop)
{
    // GIVEN
    const std::vector<std::shared_ptr<Statement>> input = {
        std::make_shared<VarStatement>(Token(TokenType::IDENTIFIER, "x", ""),
                                       std::make_shared<LiteralInt>(0)),
        std::make_shared<WhileStatement>(
            std::make_shared<Binary>(
                std::make_shared<Variable>(Token(TokenType::IDENTIFIER, "x", "")),
                Token(TokenType::LESS, "<", ""),
                std::make_shared<LiteralInt>(2)
            ),
            std::make_shared<BlockStatement>(std::vector<std::shared_ptr<Statement>>{
                std::make_shared<PrintStatement>(
                    std::make_shared<Variable>(Token(TokenType::IDENTIFIER, "x", ""))
                ),
                std::make_shared<ExpressionStatement>(
                    std::make_shared<Assign>(
                        Token(TokenType::IDENTIFIER, "x", ""),
                        std::make_shared<Binary>(
                            std::make_shared<Variable>(Token(TokenType::IDENTIFIER, "x", "")),
                            Token(TokenType::PLUS, "+", ""),
                            std::make_shared<LiteralInt>(1)
                        )
                    )
                )
            }))
    };

    // WHEN
    std::string capturedOutput;
    CAPTURE_STDOUT(capturedOutput, {
        Interpreter interpreter;
        interpreter.execute(input);
    });

    // THEN
    std::string expectedOutput = "print: 0\nprint: 1\n";
    ASSERT_EQ(capturedOutput, expectedOutput);
}

TEST(InterpreterTest, NegateAndIncrementInLoopThenPrintAandB)
{
    const std::vector<std::shared_ptr<Statement>> input = {
        // var a = true;
        std::make_shared<VarStatement>(
            Token(TokenType::IDENTIFIER, "a", ""),
            std::make_shared<LiteralBool>(true)
        ),

        // var b = 1;
        std::make_shared<VarStatement>(
            Token(TokenType::IDENTIFIER, "b", ""),
            std::make_shared<LiteralInt>(1)
        ),

        // var i = 0;
        std::make_shared<VarStatement>(
            Token(TokenType::IDENTIFIER, "i", ""),
            std::make_shared<LiteralInt>(0)
        ),

        // while (i <= 10) { a = !a; b = b + 1; i = i + 1; }
        std::make_shared<WhileStatement>(
            std::make_shared<Binary>(
                std::make_shared<Variable>(Token(TokenType::IDENTIFIER, "i", "")),
                Token(TokenType::LESS_EQUAL, "<=", ""),
                std::make_shared<LiteralInt>(10)
            ),
            std::make_shared<BlockStatement>(std::vector<std::shared_ptr<Statement>>{
                // a = !a;
                std::make_shared<ExpressionStatement>(
                    std::make_shared<Assign>(
                        Token(TokenType::IDENTIFIER, "a", ""),
                        std::make_shared<Unary>(
                            Token(TokenType::BANG, "not", ""),
                            std::make_shared<Variable>(Token(TokenType::IDENTIFIER, "a", ""))
                        )
                    )
                ),
                // b = b + 1;
                std::make_shared<ExpressionStatement>(
                    std::make_shared<Assign>(
                        Token(TokenType::IDENTIFIER, "b", ""),
                        std::make_shared<Binary>(
                            std::make_shared<Variable>(Token(TokenType::IDENTIFIER, "b", "")),
                            Token(TokenType::PLUS, "+", ""),
                            std::make_shared<LiteralInt>(1)
                        )
                    )
                ),
                // i = i + 1;
                std::make_shared<ExpressionStatement>(
                    std::make_shared<Assign>(
                        Token(TokenType::IDENTIFIER, "i", ""),
                        std::make_shared<Binary>(
                            std::make_shared<Variable>(Token(TokenType::IDENTIFIER, "i", "")),
                            Token(TokenType::PLUS, "+", ""),
                            std::make_shared<LiteralInt>(1)
                        )
                    )
                )
            })
        ),

        // print b;
        std::make_shared<PrintStatement>(
            std::make_shared<Variable>(Token(TokenType::IDENTIFIER, "b", ""))
        ),

        // print a;
        std::make_shared<PrintStatement>(
            std::make_shared<Variable>(Token(TokenType::IDENTIFIER, "a", ""))
        )
    };

    std::string capturedOutput;
    CAPTURE_STDOUT(capturedOutput, {
        Interpreter interpreter;
        interpreter.execute(input);
    });

    // b: starts at 1, incremented 11 times → 12
    // a: true, flipped 11 times → false (odd number of flips)
    std::string expectedOutput = "print: 12\nprint: false\n";
    ASSERT_EQ(capturedOutput, expectedOutput);
}
