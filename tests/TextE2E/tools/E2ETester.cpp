#include "E2ETester.h"

#include "Compiler/Compiler.h"
#include "LogManager/LogManager.h"

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
        LogManager::warn() << "Request file is empty or missing.\n";
        return false;
    }

    // Capture output
    const std::stringstream outputCapture;
    std::streambuf* originalBuffer = std::cout.rdbuf(outputCapture.rdbuf());

    // Run the compiler
    Compiler::run(requestContent);

    // Restore the original std::cout buffer
    std::cout.rdbuf(originalBuffer);

    // Compare outputs
    const std::string expectedOutput = readFile(expectedFile);
    return compareOutput(outputCapture.str(), expectedOutput);
}

std::string E2ETester::readFile(const std::string& filename)
{
    const std::string base_path = std::filesystem::current_path().string() + R"(\..\..\tests\E2E\tests\)";

    std::ifstream fileStream(base_path + filename);
    if (!fileStream.is_open())
    {
        LogManager::log() << "File " << filename << " does not exist or cannot be opened.\n";
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
        LogManager::log() << "Test passed!\n";
        return true;
    }

    LogManager::warn() << "Test failed. Output mismatch:\n"
        << "Actual:\n" << actual << "\n"
        << "Expected:\n" << expected << "\n";
    return false;
}
