// Transpiler.h
#ifndef TRANSPILER_H

#include <fstream>
#include <memory>
#include <sstream>
#include <stdexcept>

#include "Parser.h"

#include "Interpreter.h"
#include "LogManager.h"
#include "Scanner.h"

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

 public:
  static void runtimeError(const std::runtime_error& error);
};

#endif  // TRANSPILER_H