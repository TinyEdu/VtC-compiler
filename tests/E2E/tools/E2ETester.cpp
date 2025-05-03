#include "E2ETester.h"

#include "Interpreter.h"
#include "LogManager/LogManager.h"
#include "TextParser.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

E2ETester::E2ETester() = default;

std::filesystem::path E2ETester::getCurrentWorkingDirectory()
{
    return std::filesystem::current_path() / ".." / ".." / "tests" / "E2E" / "resources";
}

std::string E2ETester::getFileContent(const std::filesystem::path& filename)
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

bool E2ETester::runTest(const std::string& requestFile, const std::string& expectedFile)
{
    // Read the request content
    const std::string requestContent = getFileContent(requestFile);
    if (requestContent.empty())
    {
        LogManager::LOG() << "Request file is empty or missing.\n";
        return false;
    }

    // Capture output
    std::stringstream outputCapture;
    std::streambuf* originalBuffer = std::cout.rdbuf(outputCapture.rdbuf());

    // Run the compiler
    try
    {
        TextParser parser;
        auto parsedOutput = parser.parse(requestContent);
        Interpreter interpreter;
        interpreter.execute(parsedOutput);
    }
    catch (const std::exception& e)
    {
        std::cout.rdbuf(originalBuffer); // Ensure restoration even on exception
        LogManager::WARN() << "Exception during execution: " << e.what() << "\n";
        return false;
    }

    // Restore the original std::cout buffer
    std::cout.rdbuf(originalBuffer);

    // Compare outputs
    const std::string expectedOutput = getFileContent(expectedFile);
    if (expectedOutput.empty())
    {
        LogManager::WARN() << "Expected output file is empty or missing.\n";
        return false;
    }

    return compareOutput(outputCapture.str(), expectedOutput);
}

bool E2ETester::compareOutput(const std::string& actual, const std::string& expected)
{
    if (actual == expected)
    {
        LogManager::LOG() << "Test passed!\n";
        return true;
    }

    LogManager::WARN() << "Test failed. Output mismatch:\n"
        << "Actual:\n" << actual << "\n"
        << "Expected:\n" << expected << "\n";
    return false;
}
