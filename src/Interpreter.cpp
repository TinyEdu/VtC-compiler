#include "Interpreter.h"

std::any Interpreter::visit(Literal* expr) {
  return expr->value;
}

std::any Interpreter::visit(Grouping* expr) {
  return evaluate(expr->expression);
}

std::variant<bool, double, int, std::string> Interpreter::evaluate(Literal* expr) {
    return expr->getValue();
}

std::any Interpreter::evaluate(Expression* expr) {
  return expr->accept(this);
}

std::any Interpreter::visit(Unary* expr) {
  std::any right = evaluate(expr->right);

  switch (expr->op.type) {
    case TokenType::BANG:
        return !isTruthy(right);
    case TokenType::MINUS: 
        return -std::any_cast<double>(right);
  default:
    break;
  }
  return std::any();
}


bool Interpreter::isTruthy(std::any value) {
  if(value.empty()) {
    return false;
  }
  if (value.type() == typeid(bool)) {
    return std::any_cast<bool>(value);
  }
  
  return false;
}

template <typename T>
bool Interpreter::isEqual(T* a, T* b) {
  if ( a == nullptr && b == nullptr) {
    return true;
  }
  if(a == nullptr) {
    return false;
  }
  return a == b;
}


std::any Interpreter::visit(Binary* expr) {
  auto left = evaluate(expr->left);
  auto right = evaluate(expr->right);
  
  if (left.type() == typeid(std::string)) {
    if (expr->op.type != TokenType::PLUS) {
      throw std::runtime_error("Operands must be numbers.");
    }
    return std::any(left + right);
  }

    switch(expr->op.type) {
    case TokenType::MINUS:
      return std::any(left - right);
    case TokenType::SLASH:
        return std::any(left / right);
    case TokenType::STAR:
        return std::any(left * right);
    case TokenType::PLUS:
        return std::any(left + right); 
    case TokenType::GREATER:
        return std::any(left > right);
    case TokenType::GREATER_EQUAL:
        return std::any(left >= right);
    case TokenType::LESS:
        return std::any(left < right);
    case TokenType::LESS_EQUAL:
        return std::any(left <= right);
    case TokenType::BANG_EQUAL:
        return std::any(!isEqual(left, right);
    case TokenType::EQUAL_EQUAL:
        return std::any(isEqual(left, right));
    }
}