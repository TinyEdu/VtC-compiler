// Interpreter.h

#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <any>
#include <iostream>
#include <variant>

#include "Environment.h"
#include "LogManager.h"
#include "Token.h"

// Forward declaration of Expression classes
class Visitor;
class Expression;
class Binary;
class Grouping;
class Literal;
class Unary;
class Variable;

class Interpreter : public Visitor, public StatementVisitor {
 public:
  Interpreter();
  ~Interpreter();

  Environment* globals;
  Environment* environment;
  

 public:
  std::any visit(Assign* expr);
  std::any visit(Binary* expr);
  std::any visit(Grouping* expr);
  std::any visit(Literal* expr);
  std::any visit(Unary* expr);
  std::any visit(Variable* expr);
  std::any visit(Logical* expr);
  std::any visit(Call* expr);

  std::any visit(ExpressionStatement* stmt);
  std::any visit(IfStatement* stmt);
  std::any visit(PrintStatement* stmt);
  std::any visit(VarStatement* stmt);
  std::any visit(BlockStatement* stmt);
  std::any visit(FunctionStatement* stmt);
  std::any visit(ClassStatement* stmt);
  std::any visit(WhileStatement* stmt);

  void interpret(Expression* expr);
  void interpret(std::vector<Statement*> stmt);
  Expression* evaluate(Expression* expr);
  void executeBlock(std::vector<Statement*> stmt, Environment* env);
  void execute(Statement* stmt);
};

#endif  // INTERPRETER_H
