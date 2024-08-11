// Expression.h

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <any>
#include <string>
#include <typeinfo>
#include <variant>

#include "LogManager.h"
#include "Token.h"
#include "Visitor.h"

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

  friend std::ostream& operator<<(std::ostream& os, const Binary* expr);
};

class Grouping : public Expression {
 public:
  Grouping(Expression* expression);
  std::any accept(Visitor* visitor) override;

  Expression* expression;

  friend std::ostream& operator<<(std::ostream& os, const Grouping* expr);
};

class Unary : public Expression {
 public:
  Unary(Token op, Expression* right);
  std::any accept(Visitor* visitor) override;

  Token op;
  Expression* right;

  friend std::ostream& operator<<(std::ostream& os, const Unary* expr);
};

enum Type { STRING, INT, DOUBLE, BOOL };

class Literal : public Expression {
 public:
  Literal(void* value);
  Literal(bool value);
  Literal(const std::string& value);
  Literal(int value);
  Literal(double value);
  Literal(Type type, std::any value);

  std::any accept(Visitor* visitor);

  std::any getValue();

  template <typename T>
  T getValue() const;

  std::any value;
  Type type;

  friend Literal* operator+(const Literal& lhs, const Literal& rhs);
  friend Literal* operator-(const Literal& lhs, const Literal& rhs);
  friend Literal* operator/(const Literal& lhs, const Literal& rhs);
  friend Literal* operator*(const Literal& lhs, const Literal& rhs);

  friend bool operator!=(const Literal& lhs, const Literal& rhs);
  friend bool operator==(const Literal& lhs, const Literal& rhs);
  friend bool operator>(const Literal& lhs, const Literal& rhs);
  friend bool operator<(const Literal& lhs, const Literal& rhs);

  friend bool operator>=(const Literal& lhs, const Literal& rhs);
  friend bool operator<=(const Literal& lhs, const Literal& rhs);

  friend Literal* operator-(const Literal& lhs);
  friend Literal* operator!(const Literal& lhs);
  friend std::ostream& operator<<(std::ostream& os, const Literal* expr);
};

template <typename T>
T Literal::getValue() const {
  return std::any_cast<T>(value);
}

class Variable : public Expression {
 public:
  Variable(Token name);
  std::any accept(Visitor* visitor) override;

  Token name;
};

#endif  // EXPRESSION_H
