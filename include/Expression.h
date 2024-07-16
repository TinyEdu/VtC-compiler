#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <any>
#include <string>
#include <typeinfo>
#include <variant>
#include "Token.h"

// Forward declaration of Visitor class
class Visitor;

class Expression {
 public:
  Expression() = default;
  virtual ~Expression() = default;
  virtual std::any accept(Visitor* visitor) = 0;
};

class Binary : public Expression {
 public:
  Binary(Expression* left, Token op, Expression* right);
  std::any accept(Visitor* visitor) override;

  Expression* left;
  Token op;
  Expression* right;
};

class Grouping : public Expression {
 public:
  Grouping(Expression* expression);
  std::any accept(Visitor* visitor) override;

  Expression* expression;
};

class Literal : public Expression {
 public:
  Literal(bool value);
  Literal(double value);
  Literal(int value);
  Literal(std::string value);

  enum class Type { BOOL, DOUBLE, INT, STRING };
  Type type;
  std::any accept(Visitor* visitor) override;

  std::any value;
  std::variant<bool, double, int, std::string> getValue();
};

class Unary : public Expression {
 public:
  Unary(Token op, Expression* right);
  std::any accept(Visitor* visitor) override;

  Token op;
  Expression* right;
};

#endif  // EXPRESSION_H
