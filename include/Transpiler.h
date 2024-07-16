#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <vector>


#include "Token.h"
#include "Scanner.h"
#include "Parser.h"
#include "AstPrinter.h"

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