#ifndef STATEMENT_H
#define STATEMENT_H

#include <any>
#include "Token.h"
#include "Visitor.h"

class Statement {
 public:
  Statement() = default;
  virtual ~Statement() = default;
  virtual std::any accept(StatementVisitor* visitor) = 0;
};

class ExpressionStatement : public Statement {
 public:
  ExpressionStatement(Expression* expression)
      : expression(expression) {}
  ~ExpressionStatement() = default;

  std::any accept(StatementVisitor* visitor) override {
    return visitor->visit(this);
  }

  Expression* expression;
};

class IfStatement : public Statement {
 public:
  IfStatement(Expression* condition, Statement* thenBranch,
              Statement* elseBranch)
      : condition(condition),
        thenBranch(thenBranch),
        elseBranch(elseBranch) {}

  ~IfStatement() = default;

  std::any accept(StatementVisitor* visitor) override {
    return visitor->visit(this);
  }

  Expression* condition;
  Statement* thenBranch;
  Statement* elseBranch;
};

class WhileStatement : public Statement {
 public:
  WhileStatement(Expression* condition, Statement* body)
      : condition(condition), body(body) {}
  ~WhileStatement() = default;

  std::any accept(StatementVisitor* visitor) override {
    return visitor->visit(this);
  }

  Expression* condition;
  Statement* body;
};

class PrintStatement : public Statement {
 public:
  PrintStatement(Expression* expression) : expression(expression) {}
  ~PrintStatement() = default;

  std::any accept(StatementVisitor* visitor) override {
    return visitor->visit(this);
  }

  Expression* expression;
};

class VarStatement : public Statement {
 public:
  VarStatement(Token name, Expression* initializer)
      : name(name), initializer(initializer) {}
  ~VarStatement() = default;

  std::any accept(StatementVisitor* visitor) override {
    return visitor->visit(this);
  }

  Token name;
  Expression* initializer;
};

class BlockStatement : public Statement {
 public:
  BlockStatement(std::vector<Statement*> statements)
      : statements(statements) {}
  ~BlockStatement() = default;

  std::any accept(StatementVisitor* visitor) override {
    return visitor->visit(this);
  }

  std::vector<Statement*> statements;
};

class FunctionStatement : public Statement {
 public:
  FunctionStatement(Token name, std::vector<Token> params,
                    std::vector<Statement*> body)
      : name(name),
        params(params),
        body(body) {}
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
  ClassStatement(Token name, std::vector<FunctionStatement*> methods)
      : name(name), methods(methods) {}
  ~ClassStatement() = default;

  std::any accept(StatementVisitor* visitor) override {
    return visitor->visit(this);
  }

  Token name;
  std::vector<FunctionStatement*> methods;
};

#endif  // STATEMENT_H
