// Compiler.h

#ifndef COMPILER_H
#define COMPILER_H

#include <string>
#include <stdexcept>

class Interpreter;

class Compiler
{
public:
    Compiler();
    ~Compiler();

    static bool hadError;
    static bool hadRuntimeError;

    static Interpreter interpreter;
    static void runFile(const char* file);
    static void runPrompt();

    static void run(const std::string& source);

    static void runtimeError(const std::runtime_error& error);
};

#endif //COMPILER_H
