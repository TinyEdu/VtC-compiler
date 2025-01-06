// Compiler.h

#ifndef COMPILER_H
#define COMPILER_H

#include <fstream>
#include <memory>
#include <sstream>
#include <stdexcept>

// #include "Interpreter.h"
#include "LogManager/LogManager.h"
#include "Scanner/Scanner.h"
#include "Parser/Parser.h"

class Compiler
{
public:
    Compiler();
    ~Compiler();

public:
    static bool hadError;
    static bool hadRuntimeError;

public:
    //static Interpreter interpreter;
    static void runFile(const char* file);
    static void runPrompt();

private:
    static void run(const std::string_view source);

public:
    static void runtimeError(const std::runtime_error& error);
};

#endif //COMPILER_H
