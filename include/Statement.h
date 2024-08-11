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

class VarStatement : public Statement {
  public:
    VarStatement(Token name, Expression* initializer) : name(std::move(name)), initializer(std::move(initializer)) {}
    ~VarStatement() = default;
  
    std::any accept(StatementVisitor* visitor) override {
      return visitor->visit(this);
    }
  
    Token name;
    Expression* initializer;
  };

class BlockStatement : public Statement {
 public:
  BlockStatement(std::vector<Statement*> statements) : statements(std::move(statements)) {}
  ~BlockStatement() = default;

  std::any accept(StatementVisitor* visitor) override {
    return visitor->visit(this);
  }

  std::vector<Statement*> statements;
};

class FunctionStatement : public Statement {
 public:
  FunctionStatement(Token name, std::vector<Token> params, std::vector<Statement*> body) : name(std::move(name)), params(std::move(params)), body(std::move(body)) {}
  ~FunctionStatement() = default;

  std::any accept(StatementVisitor* visitor) override {
    return visitor->visit(this);
  }

  Token name;
  std::vector<Token> params;
  std::vector<Statement*> body;
};

class ClassStatement : public Statement {
 public:
  ClassStatement(Token name, std::vector<FunctionStatement*> methods) : name(std::move(name)), methods(std::move(methods)) {}
  ~ClassStatement() = default;

  std::any accept(StatementVisitor* visitor) override {
    return visitor->visit(this);
  }

  Token name;
  std::vector<FunctionStatement*> methods;
};

#endif // STATEMENT_H
