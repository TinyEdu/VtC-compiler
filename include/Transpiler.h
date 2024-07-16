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