#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "AstPrinter.h"
#include "Parser.h"
#include "Scanner.h"
#include "Token.h"
#include "Interpreter.h"


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
};