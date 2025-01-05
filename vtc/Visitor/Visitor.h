// Visitor.h

#ifndef VISITOR_H
#define VISITOR_H

#include <Expressions/ExpressionsWorld.h>
#include <Statements/Statement.h>

#include <variant>
#include <any>

class ReturnStatement;
class WhileStatement;
class IfStatement;
class ClassStatement;
class FunctionStatement;
class BlockStatement;
class VarStatement;
class PrintStatement;
class ExpressionStatement;

class BaseVisitor {};

class Visitor : public BaseVisitor {
 public:
  virtual std::any visit(Assign* expr) = 0;
  virtual std::any visit(Binary* expr) = 0;
  virtual std::any visit(Grouping* expr) = 0;
  virtual std::any visit(Literal* expr) = 0;
  virtual std::any visit(Unary* expr) = 0;
  virtual std::any visit(Variable* expr) = 0;
  virtual std::any visit(Logical* expr) = 0;
  virtual std::any visit(Call* expr) = 0;
};

class StatementVisitor : public BaseVisitor {
 public:
  virtual std::any visit(ExpressionStatement* stmt) = 0;
  virtual std::any visit(PrintStatement* stmt) = 0;
  virtual std::any visit(VarStatement* stmt) = 0;
  virtual std::any visit(BlockStatement* stmt) = 0;
  virtual std::any visit(FunctionStatement* stmt) = 0;
  virtual std::any visit(ClassStatement* stmt) = 0;
  virtual std::any visit(IfStatement* stmt) = 0;
  virtual std::any visit(WhileStatement* stmt) = 0;
  virtual std::any visit(ReturnStatement* stmt) = 0;
};

#endif  // VISITOR_H