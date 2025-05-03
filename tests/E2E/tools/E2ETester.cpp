#include "E2ETester.h"

#include "Interpreter.h"
#include "LogManager/LogManager.h"
#include "TextParser.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

E2ETester::E2ETester() = default;

bool E2ETester::runTest(const std::string& requestFile, const std::string& expectedFile)
{
    // Read the request content
    const std::string requestContent = readFile(requestFile);
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
    const std::string expectedOutput = readFile(expectedFile);
    if (expectedOutput.empty())
    {
        LogManager::WARN() << "Expected output file is empty or missing.\n";
        return false;
    }

    return compareOutput(outputCapture.str(), expectedOutput);
}

std::string E2ETester::readFile(const std::string& filename)
{
    std::filesystem::path basePath = std::filesystem::current_path() / ".." / ".." / "resources" / "E2E" / "tests";
    std::filesystem::path filePath = basePath / filename;

    std::ifstream fileStream(filePath);
    if (!fileStream)
    {
        LogManager::LOG() << "File " << filePath << " does not exist or cannot be opened.\n";
        return "";
    }

    std::stringstream buffer;
    buffer << fileStream.rdbuf();
    return buffer.str();
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
