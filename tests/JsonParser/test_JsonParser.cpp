#include <gtest/gtest.h>
#include "JsonParser.h"

#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>


std::filesystem::path getCurrentWorkingDirectory() {
    return std::filesystem::current_path() / ".."/ ".."/ "tests" / "JsonParser" / "resources";
}

std::string getFileContent(const std::filesystem::path& filename) {
    const std::filesystem::path filePath = getCurrentWorkingDirectory() / filename;

    std::cout << "Current path: " << filePath << std::endl;

    std::ifstream fileStream(filePath, std::ios::in);
    if (!fileStream) {
        throw std::runtime_error("Failed to open file: " + filePath.string());
    }

    std::ostringstream contentStream;
    contentStream << fileStream.rdbuf();

    return contentStream.str();
}

TEST(JsonParserTest, ParsesValidInput) {
    std::string input = getFileContent("input1.json");
    std::cout << "Input: " << input << std::endl;
    JsonParser parser;
    auto result = parser.parse(input);
    ASSERT_FALSE(result.empty()) << "Parsed result should not be empty.";
}
