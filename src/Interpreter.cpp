#include "Expression.h"
#include "Visitor.h"

#include "Interpreter.h"

Interpreter::Interpreter() {}

void Interpreter::interpret(Expression* expr) {
    try {
        Literal* value = std::any_cast<Literal*>(evaluate(expr));

        // Print the expression
        std::cout << value << std::endl;    

    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}


std::any Interpreter::visit(Literal* expr) {  // @TODO - do I want to return this for sure?
    return expr->getValue<std::any>();
}


std::any Interpreter::visit(Grouping* expr) {
    return evaluate(expr->expression);
}


std::any Interpreter::evaluate(Expression* expr) {
    return expr->accept(this);
}


std::any Interpreter::visit(Unary* expr) {
    Literal* right = std::any_cast<Literal*>(evaluate(expr->right)); // @TODO : Do I want to visit always return Literal in this case? 

    switch (expr->op.type) {
        case TokenType::BANG:
            // return !isTruthy(right);
            return !right;
        case TokenType::MINUS:
            // return -std::any_cast<double>(right);
            return -*right;
        default:
            break;
    }
    return std::any();
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


void Interpreter::checkNumberOperands(Token op, std::any left, std::any right) {
    if (left.type() == typeid(double) && right.type() == typeid(double)) {
        return;
    }
    throw std::runtime_error("Operands must be numbers.");
}


Interpreter::~Interpreter() {}


std::any Interpreter::visit(Binary* expr) {
  Literal* left = std::any_cast<Literal*>(evaluate(expr->left));
  Literal* right = std::any_cast<Literal*>(evaluate(expr->right));

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
