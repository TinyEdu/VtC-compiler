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
#include <Expressions/Literals/LiteralInt.h>
#include <Expressions/Literals/LiteralString.h>

#include "Statements/BlockStatement.h"
#include "Statements/ExpressionStatement.h"
#include "Statements/IfStatement.h"
#include "Statements/PrintStatement.h"
#include "Statements/VarStatement.h"

JsonParser parser;
// result of parse is -> const std::vector<std::shared_ptr<Statement>>

std::filesystem::path getCurrentWorkingDirectory()
{
    return std::filesystem::current_path() / ".." / ".." / "tests" / "JsonParser" / "resources";
}

std::string getFileContent(const std::filesystem::path& filename)
{
    const std::filesystem::path filePath = getCurrentWorkingDirectory() / filename;

    std::cout << "Current path: " << filePath << std::endl;

    std::ifstream fileStream(filePath, std::ios::in);
    if (!fileStream)
    {
        throw std::runtime_error("Failed to open file: " + filePath.string());
    }

    std::ostringstream contentStream;
    contentStream << fileStream.rdbuf();

    return contentStream.str();
}

TEST(JsonParserTest, EmptyProject)
{
    // GIVEN
    const std::string input = getFileContent("01/input.json");

    // WHEN
    const std::vector<std::shared_ptr<Statement>> result = parser.parse(input);

    // THEN
    ASSERT_TRUE(result.empty()) << "Parsed result should be empty for this test case";
}

TEST(JsonParserTest, PrintStringByValue)
{
    // GIVEN
    const std::string input = getFileContent("02/input.json");

    // WHEN
    const std::vector<std::shared_ptr<Statement>> output = parser.parse(input);

    // THEN
    const std::vector<std::shared_ptr<Statement>> expectedOutput = {
        std::make_shared<PrintStatement>(
            std::make_shared<LiteralString>("printing!")
        )
    };

    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output.size(), expectedOutput.size());
    for (size_t i = 0; i < output.size(); i ++)
    {
        ASSERT_TRUE(*output[i] == *expectedOutput[i])
            << "Parsed result does not match expected output at index " << i;
    }
}

TEST(JsonParserTest, PrintStringBySignal)
{
    // GIVEN
    const std::string input = getFileContent("03/input.json");

    // WHEN
    const std::vector<std::shared_ptr<Statement>> output = parser.parse(input);

    // THEN
    const std::vector<std::shared_ptr<Statement>> expectedOutput = {
        std::make_shared<PrintStatement>(
            std::make_shared<LiteralString>("printing!")
        )
    };

    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output.size(), expectedOutput.size());
    for (size_t i = 0; i < output.size(); i ++)
    {
        ASSERT_TRUE(*output[i] == *expectedOutput[i])
            << "Parsed result does not match expected output at index " << i;
    }
}

TEST(JsonParserTest, CreateVarBySignal)
{
    // GIVEN
    const std::string input = getFileContent("04/input.json");

    // WHEN
    const std::vector<std::shared_ptr<Statement>> output = parser.parse(input);

    // THEN
    const std::vector<std::shared_ptr<Statement>> expectedOutput = {
        std::make_shared<VarStatement>(
            Token(TokenType::IDENTIFIER, "var", "", 1),
            std::make_shared<LiteralString>("val"))
    };

    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output.size(), expectedOutput.size());
    for (size_t i = 0; i < output.size(); i ++)
    {
        ASSERT_TRUE(*output[i] == *expectedOutput[i])
            << "Parsed result does not match expected output at index " << i;
    }
}

TEST(JsonParserTest, CreateVarByValue)
{
    // GIVEN
    const std::string input = getFileContent("05/input.json");

    // WHEN
    const std::vector<std::shared_ptr<Statement>> output = parser.parse(input);

    // THEN
    const std::vector<std::shared_ptr<Statement>> expectedOutput = {
        std::make_shared<VarStatement>(
            Token(TokenType::IDENTIFIER, "var", "", 1),
            std::make_shared<LiteralString>("val"))
    };

    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output.size(), expectedOutput.size());
    for (size_t i = 0; i < output.size(); i ++)
    {
        ASSERT_TRUE(*output[i] == *expectedOutput[i])
            << "Parsed result does not match expected output at index " << i;
    }
}

TEST(JsonParserTest, GetVarPrint)
{
    // GIVEN
    const std::string input = getFileContent("06/input.json");

    // WHEN
    const std::vector<std::shared_ptr<Statement>> output = parser.parse(input);

    // THEN
    const std::vector<std::shared_ptr<Statement>> expectedOutput = {
        std::make_shared<PrintStatement>(
            std::make_shared<Variable>(Token(TokenType::VAR, "hello", "", 1))
        )
    };

    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output.size(), expectedOutput.size());
    for (size_t i = 0; i < output.size(); i ++)
    {
        ASSERT_TRUE(*output[i] == *expectedOutput[i])
            << "Parsed result does not match expected output at index " << i;
    }
}

TEST(JsonParserTest, BinaryOperation)
{
    // GIVEN
    const std::string input = getFileContent("07/input.json");

    // WHEN
    const std::vector<std::shared_ptr<Statement>> output = parser.parse(input);

    // THEN
    const std::vector<std::shared_ptr<Statement>> expectedOutput = {
        std::make_shared<VarStatement>(
            Token(TokenType::IDENTIFIER, "var", "", 1),
            std::make_shared<Binary>(
                std::make_shared<LiteralInt>(99),
                Token(TokenType::PLUS, "add", "", 0),
                std::make_shared<LiteralInt>(1)))
    };

    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output.size(), expectedOutput.size());
    for (size_t i = 0; i < output.size(); i ++)
    {
        ASSERT_TRUE(*output[i] == *expectedOutput[i])
            << "Parsed result does not match expected output at index " << i;
    }
}

TEST(JsonParserTest, DoubleBinaryOperation)
{
    // GIVEN
    const std::string input = getFileContent("08/input.json");

    // WHEN
    const std::vector<std::shared_ptr<Statement>> output = parser.parse(input);

    // THEN
    const std::vector<std::shared_ptr<Statement>> expectedOutput = {
        std::make_shared<VarStatement>(
            Token(TokenType::IDENTIFIER, "var", "", 1),
            std::make_shared<Binary>(
                std::make_shared<LiteralInt>(99),
                Token(TokenType::PLUS, "add", "", 0),
                std::make_shared<Binary>(
                    std::make_shared<LiteralInt>(2),
                    Token(TokenType::MINUS, "subtract", "", 0),
                    std::make_shared<LiteralInt>(1))))
    };

    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output.size(), expectedOutput.size());
    for (size_t i = 0; i < output.size(); i ++)
    {
        ASSERT_TRUE(*output[i] == *expectedOutput[i])
            << "Parsed result does not match expected output at index " << i;
    }
}

TEST(JsonParserTest, UnaryWithBinaryOperation)
{
    // GIVEN
    const std::string input = getFileContent("09/input.json");

    // WHEN
    const std::vector<std::shared_ptr<Statement>> output = parser.parse(input);

    // THEN
    const std::vector<std::shared_ptr<Statement>> expectedOutput = {
        std::make_shared<VarStatement>(
            Token(TokenType::IDENTIFIER, "var", "", 1),
            std::make_shared<Binary>(
                std::make_shared<LiteralInt>(99),
                Token(TokenType::PLUS, "add", "", 0),
                std::make_shared<Unary>(
                    Token(TokenType::MINUS, "negate", "", 0),
                    std::make_shared<LiteralInt>(1))))
    };

    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output.size(), expectedOutput.size());
    for (size_t i = 0; i < output.size(); i ++)
    {
        ASSERT_TRUE(*output[i] == *expectedOutput[i])
            << "Parsed result does not match expected output at index " << i;
    }
}

TEST(JsonParserTest, CreateVarWithBinaryUsingGetVar)
{
    // GIVEN
    const std::string input = getFileContent("10/input.json");

    // WHEN
    const std::vector<std::shared_ptr<Statement>> output = parser.parse(input);

    // THEN
    const std::vector<std::shared_ptr<Statement>> expectedOutput = {
        std::make_shared<VarStatement>(
            Token(TokenType::IDENTIFIER, "var", "", 1),
            std::make_shared<LiteralInt>(99)),
        std::make_shared<PrintStatement>(
            std::make_shared<Binary>(
                std::make_shared<LiteralInt>(1),
                Token(TokenType::PLUS, "add", "", 0),
                std::make_shared<Variable>(Token(TokenType::VAR, "var", "", 1))))
    };

    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output.size(), expectedOutput.size());
    for (size_t i = 0; i < output.size(); i ++)
    {
        ASSERT_TRUE(*output[i] == *expectedOutput[i])
            << "Parsed result does not match expected output at index " << i;
    }
}

TEST(JsonParserTest, IfStatement)
{
    // GIVEN
    const std::string input = getFileContent("11/input.json");

    // WHEN
    const std::vector<std::shared_ptr<Statement>> output = parser.parse(input);

    // THEN
    // This would look like this in text: 'if ( 100 >= 10 ) { print("TRU") } else { print("FLS") }'
    auto ifCondition = std::make_shared<Binary>(
        std::make_shared<LiteralInt>(100),
        Token(TokenType::GREATER_EQUAL, ">=", "", 0),
        std::make_shared<LiteralInt>(10)
    );

    std::vector<std::shared_ptr<Statement>> ifBodyStatements = {
        std::make_shared<PrintStatement>(std::make_shared<LiteralString>("TRU"))
    };
    std::vector<std::shared_ptr<Statement>> elseBodyStatements = {
        std::make_shared<PrintStatement>(std::make_shared<LiteralString>("FLS"))
    };

    auto ifTrueBranch = std::make_shared<BlockStatement>(ifBodyStatements);
    auto ifFalseBranch = std::make_shared<BlockStatement>(elseBodyStatements);

    const std::vector<std::shared_ptr<Statement>> expectedOutput = {
        std::make_shared<IfStatement>(ifCondition, ifTrueBranch, ifFalseBranch)
    };

    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output.size(), expectedOutput.size());
    for (size_t i = 0; i < output.size(); i ++)
    {
        ASSERT_TRUE(*output[i] == *expectedOutput[i])
            << "Parsed result does not match expected output at index " << i;
    }
}

TEST(JsonParserTest, PlainForLoop)
{
    // GIVEN
    const std::string input = getFileContent("12/input.json");

    // WHEN
    const std::vector<std::shared_ptr<Statement>> output = parser.parse(input);

    // THEN
    const std::vector<std::shared_ptr<Statement>> expectedOutput = {};

    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output.size(), expectedOutput.size());
    for (size_t i = 0; i < output.size(); i ++)
    {
        ASSERT_TRUE(*output[i] == *expectedOutput[i])
            << "Parsed result does not match expected output at index " << i;
    }
}

TEST(JsonParserTest, ForLoopWithPrintingIncrement)
{
    // GIVEN
    const std::string input = getFileContent("13/input.json");

    // WHEN
    const std::vector<std::shared_ptr<Statement>> output = parser.parse(input);

    // THEN
    const std::vector<std::shared_ptr<Statement>> expectedOutput = {};

    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output.size(), expectedOutput.size());
    for (size_t i = 0; i < output.size(); i ++)
    {
        ASSERT_TRUE(*output[i] == *expectedOutput[i])
            << "Parsed result does not match expected output at index " << i;
    }
}

TEST(JsonParserTest, CallAndListen)
{
    // GIVEN
    const std::string input = getFileContent("14/input.json");

    // WHEN
    const std::vector<std::shared_ptr<Statement>> output = parser.parse(input);

    // THEN
    const std::vector<std::shared_ptr<Statement>> expectedOutput = {};

    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output.size(), expectedOutput.size());
    for (size_t i = 0; i < output.size(); i ++)
    {
        ASSERT_TRUE(*output[i] == *expectedOutput[i])
            << "Parsed result does not match expected output at index " << i;
    }
}

TEST(JsonParserTest, ComplexExpressionOperations)
{
    // GIVEN
    const std::string input = getFileContent("15/input.json");

    // WHEN
    const std::vector<std::shared_ptr<Statement>> output = parser.parse(input);

    // THEN
    const std::vector<std::shared_ptr<Statement>> expectedOutput = {};

    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output.size(), expectedOutput.size());
    for (size_t i = 0; i < output.size(); i ++)
    {
        ASSERT_TRUE(*output[i] == *expectedOutput[i])
            << "Parsed result does not match expected output at index " << i;
    }
}

TEST(JsonParserTest, ComplexExampleWithCallListenGetSetCreatePrintBinaryOperation)
{
    // GIVEN
    const std::string input = getFileContent("16/input.json");

    // WHEN
    const std::vector<std::shared_ptr<Statement>> output = parser.parse(input);

    // THEN
    const std::vector<std::shared_ptr<Statement>> expectedOutput = {};

    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output.size(), expectedOutput.size());
    for (size_t i = 0; i < output.size(); i ++)
    {
        ASSERT_TRUE(*output[i] == *expectedOutput[i])
            << "Parsed result does not match expected output at index " << i;
    }
}