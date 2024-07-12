#include <string>
#include <iostream>


class ErrorHandler {
public:
    ErrorHandler();
    ~ErrorHandler();

    static void error(int line, const std::string& message);
    static void report(int line, const std::string& where, const std::string& message);

    bool hadError();
    bool hadRuntimeError();
};

