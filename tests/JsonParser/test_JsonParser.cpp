#include <gtest/gtest.h>
#include "JsonParser.h"

#include <filesystem>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <Expressions/Literals/LiteralString.h>

#include "Statements/PrintStatement.h"

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
        std::make_shared<PrintStatement>(
            std::make_shared<LiteralString>("printing!")
        )
    };

    ASSERT_EQ(output.size(), expectedOutput.size());
    for (size_t i = 0; i < output.size(); i ++)
    {
        ASSERT_TRUE(*output[i] == *expectedOutput[i])
            << "Parsed result does not match expected output at index " << i;
    }
}

