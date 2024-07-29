#include "Interpreter.h"

Interpreter::Interpreter() {}

void Interpreter::interpret(Expression* expr) {
    try {
        std::any value = evaluate(expr);
        std::cout << std::any_cast<double>(value) << std::endl;
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}



std::any Interpreter::visit(Literal* expr) {
    return expr->getValue();
}

std::any Interpreter::visit(Grouping* expr) {
    return evaluate(expr->expression);
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
    if(!value.has_value()) {
        return false;
    }
    if (value.type() == typeid(bool)) {
        return std::any_cast<bool>(value);
    }
    if (value.type() == typeid(double)) {
        return std::any_cast<double>(value) != 0;
    }
    return true;
}

bool Interpreter::isEqual(std::any a, std::any b) {
    if (a.type() != b.type()) {
        return false;
    }
    if (a.type() == typeid(bool)) {
        return std::any_cast<bool>(a) == std::any_cast<bool>(b);
    }
    if (a.type() == typeid(double)) {
        return std::any_cast<double>(a) == std::any_cast<double>(b);
    }
    if (a.type() == typeid(std::string)) {
        return std::any_cast<std::string>(a) == std::any_cast<std::string>(b);
    }
    return false;
}

void Interpreter::checkNumberOperand(Token op, std::any operand) {
    if (operand.type() == typeid(double)) {
        return;
    }
    throw std::runtime_error("Operand must be a number.");
}

std::string Interpreter::stringify(std::any value) {
    if (value.type() == typeid(double)) {
        std::string text = std::to_string(std::any_cast<double>(value));
        return text;
    }
    if (value.type() == typeid(bool)) {
        return std::any_cast<bool>(value) ? "true" : "false";
    }
    if (value.type() == typeid(std::string)) {
        return std::any_cast<std::string>(value);
    }
    return "";
}

void Interpreter::checkNumberOperands(Token op, std::any left, std::any right) {
    if (left.type() == typeid(double) && right.type() == typeid(double)) {
        return;
    }
    throw std::runtime_error("Operands must be numbers.");
}

Interpreter::~Interpreter() {}

std::any Interpreter::visit(Binary* expr) {
  std::any left = evaluate(expr->left);
  std::any right = evaluate(expr->right);

  if (left.type() == typeid(std::string) &&
      right.type() == typeid(std::string)) {
    if (expr->op.type != TokenType::PLUS) {
      throw std::runtime_error("Operands must be numbers.");
    }
    return std::any(std::any_cast<std::string>(left) +
                    std::any_cast<std::string>(right));
  }

  double leftValue = std::any_cast<double>(left);
  double rightValue = std::any_cast<double>(right);

  switch (expr->op.type) {
    case TokenType::MINUS:
      checkNumberOperand(expr->op, right);
      return std::any(leftValue - rightValue);
    case TokenType::SLASH:
      return std::any(leftValue / rightValue);
    case TokenType::STAR:
      return std::any(leftValue * rightValue);
    case TokenType::PLUS:
      return std::any(leftValue + rightValue);
    case TokenType::GREATER:
      return std::any(leftValue > rightValue);
    case TokenType::GREATER_EQUAL:
      return std::any(leftValue >= rightValue);
    case TokenType::LESS:
      return std::any(leftValue < rightValue);
    case TokenType::LESS_EQUAL:
      return std::any(leftValue <= rightValue);
    case TokenType::BANG_EQUAL:
      return std::any(!isEqual(left, right));
    case TokenType::EQUAL_EQUAL:
      return std::any(isEqual(left, right));
    default:
      break;
  }
  return std::any();
}
