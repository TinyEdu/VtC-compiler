// Interpreter.h

#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <any>
#include <iostream>
#include <variant>

#include "LogManager.h"
#include "Token.h"

// Forward declaration of Expression classes
class Visitor;
class Expression;
class Binary;
class Grouping;
class Literal;
class Unary;

class Interpreter : public Visitor, public StatementVisitor {
 public:
  Interpreter();
  ~Interpreter();

 public:
  std::any visit(Binary* expr);
  std::any visit(Grouping* expr);
  std::any visit(Literal* expr);
  std::any visit(Unary* expr);

  std::any visit(ExpressionStatement* stmt);
  std::any visit(PrintStatement* stmt);

  void interpret(Expression* expr);
  void interpret(std::vector<Statement*> stmt);
  Literal* evaluate(Expression* expr);
  std::variant<bool, double, int, std::string> evaluate(Literal* expr);
};

#endif  // INTERPRETER_H
