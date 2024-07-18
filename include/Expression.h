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


class Unary : public Expression {
 public:
  Unary(Token op, Expression* right);
  std::any accept(Visitor* visitor) override;

  Token op;
  Expression* right;
};

#include <memory>
#include <typeinfo>
#include <string>
#include <stdexcept>
#include <type_traits>

class Literal : public Expression {
public:
    template<typename T>
    Literal(T value) : valueHolder(std::make_shared<ValueHolder<T>>(value)) {}

    template<typename T>
    T getValue() const {
        if (auto ptr = std::dynamic_pointer_cast<ValueHolder<T>>(valueHolder)) {
            return ptr->value;
        } else {
            throw std::bad_cast();
        }
    }

    std::type_info const& getType() const {
        return valueHolder->getType();
    }

    std::any accept(Visitor* visitor) override;

private:
    struct BaseValueHolder {
        virtual ~BaseValueHolder() = default;
        virtual std::type_info const& getType() const = 0;
    };

    template<typename T>
    struct ValueHolder : BaseValueHolder {
        ValueHolder(T value) : value(value) {}
        T value;

        std::type_info const& getType() const override {
            return typeid(T);
        }
    };

    std::shared_ptr<BaseValueHolder> valueHolder;
};


#endif  // EXPRESSION_H
