#include <iostream>
#include "AstPrinter.h"

int main(int argc, char* argv[]) {
  std::cout << "Running compiler...\n";

  
  AstPrinter printer;

  Binary* expression = new Binary(new Literal(1), Token(TokenType::PLUS, "+", " ", 1), new Literal(2));
  Expression* expr = new Binary(
    new Unary(Token(TokenType::MINUS, "-", " ", 1), new Literal(23)),
    Token(TokenType::STAR, "*", " ", 1),
    new Grouping(new Literal(45))
  );

  std::cout << printer.print(expression) << std::endl;

  return 1;
}