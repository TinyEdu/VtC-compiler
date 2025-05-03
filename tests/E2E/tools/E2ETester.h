#ifndef E2ETESTER_H
#define E2ETESTER_H

#include <filesystem>
#include <string>

class E2ETester
{
public:
    E2ETester();
    static std::filesystem::path getCurrentWorkingDirectory();
    static std::string getFileContent(const std::filesystem::path& filename);
    static bool runTest(const std::string& requestFile, const std::string& expectedFile);

private:
    static bool compareOutput(const std::string& actual, const std::string& expected);
};

#endif // E2ETESTER_H
