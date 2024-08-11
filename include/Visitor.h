// Visitor.h

#ifndef VISITOR_H
#define VISITOR_H

#include <any>

// Forward declaration of Expression classes
class Binary;
class Grouping;
class Literal;
class Unary;
class Expression;

class BaseVisitor {

};

class Visitor : public BaseVisitor {
 public:
  virtual std::any visit(Binary* expr) = 0;
  virtual std::any visit(Grouping* expr) = 0;
  virtual std::any visit(Literal* expr) = 0;
  virtual std::any visit(Unary* expr) = 0;

};

class Statement;
class ExpressionStatement;
class PrintStatement;

class StatementVisitor : public BaseVisitor {
  public:
    virtual std::any visit(ExpressionStatement* stmt) = 0;
    virtual std::any visit(PrintStatement* stmt) = 0;
};

#endif  // VISITOR_H