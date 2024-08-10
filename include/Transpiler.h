// Transpiler.h
#ifndef TRANSPILER_H

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "AstPrinter.h"
#include "Parser.h"

#include "Scanner.h"
#include "Interpreter.h"
#include "LogManager.h"


class RuntimeError {
public:
    std::string message;
    Token token;

    std::string getMessage() const {
        return message;
    }

    // Constructor
    RuntimeError(const std::string& msg, const Token& tok) : message(msg), token(tok) {}
};


class Transpiler {
 public:
  Transpiler();
  ~Transpiler();

 public:
  static bool hadError;
  static bool hadRuntimeError;

 public:
  static Interpreter interpreter;
  static void runFile(const char* file);
  static void runPrompt();

 private:
  static void run(std::string source);
  static void runtimeError(RuntimeError error);
};

#endif  // TRANSPILER_H