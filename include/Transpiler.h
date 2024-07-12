#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <vector>

#include "Scanner.h"
#include "Token.h"


class Transpiler {
public:
    Transpiler();
    ~Transpiler();

public:
static bool hadError;

public:
    static void runFile(const char* file);
    static void runPrompt();

private:
    static void run(std::string source);
};