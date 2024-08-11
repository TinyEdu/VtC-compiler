#ifndef STATEMENT_H
#define STATEMENT_H

#include <any>
#include "Visitor.h"

class Statement {
 public:
  Statement() = default;
  virtual ~Statement() = default;
  virtual std::any accept(StatementVisitor* visitor) = 0;
};

class ExpressionStatement : public Statement {
 public:
  ExpressionStatement(Expression* expression) : expression(std::move(expression)) {}
  ~ExpressionStatement() = default;

  std::any accept(StatementVisitor* visitor) override {
    return visitor->visit(this);
  }

  Expression* expression;
};

class PrintStatement : public Statement {
 public:
  PrintStatement(Expression* expression) : expression(std::move(expression)) {}
  ~PrintStatement() = default;

  std::any accept(StatementVisitor* visitor) override {
    return visitor->visit(this);
  }

 Expression* expression;
};


#endif // STATEMENT_H