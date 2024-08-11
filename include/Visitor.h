// Visitor.h

#ifndef VISITOR_H
#define VISITOR_H

#include <any>

// Forward declaration of Expression classes
class Assign;
class Binary;
class Grouping;
class Literal;
class Unary;
class Expression;
class Variable;

class BaseVisitor {};

class Visitor : public BaseVisitor {
 public:
  virtual std::any visit(Assign* expr) = 0;
  virtual std::any visit(Binary* expr) = 0;
  virtual std::any visit(Grouping* expr) = 0;
  virtual std::any visit(Literal* expr) = 0;
  virtual std::any visit(Unary* expr) = 0;
  virtual std::any visit(Variable* expr) = 0;
};

class Statement;
class ExpressionStatement;
class PrintStatement;
class VarStatement;
class BlockStatement;
class FunctionStatement;
class ClassStatement;

class StatementVisitor : public BaseVisitor {
 public:
  virtual std::any visit(ExpressionStatement* stmt) = 0;
  virtual std::any visit(PrintStatement* stmt) = 0;
  virtual std::any visit(VarStatement* stmt) = 0;
  virtual std::any visit(BlockStatement* stmt) = 0;
  virtual std::any visit(FunctionStatement* stmt) = 0;
  virtual std::any visit(ClassStatement* stmt) = 0;
};

#endif  // VISITOR_H