#include <iostream>
#include "Transpiler.h"
#include "Expression.h"
#include "AstPrinter.h"


int main(int argc, char* argv[]) {
  std::cout << "Running compiler...\n";
  AstPrinter printer;
  Binary<std::string>* expression = new Binary<std::string>(new Literal<std::string>("1"), Token(TokenType::PLUS, "+", " ", 1), new Literal<std::string>("2"));
  Expression<std::string>* expr = new Binary<std::string>(
    new Unary<std::string>(Token(TokenType::MINUS, "-", " ", 1), new Literal<std::string>("123")),
    Token(TokenType::STAR, "*", " ", 1),
    new Grouping<std::string>(new Literal<std::string>("45"))
  );

  std::cout << printer.print(expr) << "\n";

  return 1;  
  
  if (argc > 2) {
    std::cerr << "Error: Wrong input amount.\n";
    return 65;  // https://man.freebsd.org/cgi/man.cgi?query=sysexits&apropos=0&sektion=0&manpath=FreeBSD+4.3-RELEASE&format=html
  }
  else if (argc == 2) {
    std::clog << "Compiling file: " << argv[1] << "...\n";
    Transpiler::runFile(argv[1]);
  }
  else { // argc == 1 
    std::clog << "Real life compilation... \nPrompting :>\n";
    Transpiler::runPrompt();
  }

  return 1;
}