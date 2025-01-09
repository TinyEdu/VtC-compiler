#ifndef E2ETESTER_H
#define E2ETESTER_H

#include <string>

class E2ETester
{
public:
    E2ETester();
    static bool runTest(const std::string& requestFile, const std::string& expectedFile);

private:
    static std::string readFile(const std::string& filename);
    static bool compareOutput(const std::string& actual, const std::string& expected);
};

#endif // E2ETESTER_H
