#include "Expression.h"
#include "Visitor.h"

#include "Interpreter.h"

Interpreter::Interpreter() {}

void Interpreter::interpret(Expression* expr) {

        std::cout << "errroo\n\n\n";
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

    std::cout << "Unreachable code reached in Interpreter::visit(Unary* expr) " << std::endl;
    return std::any();
}


Interpreter::~Interpreter() {}


std::any Interpreter::visit(Binary* expr) {
  Literal left = std::any_cast<Literal>(evaluate(expr->left));
  Literal right = std::any_cast<Literal>(evaluate(expr->right));

  switch (expr->op.type) {
    case TokenType::MINUS:
      return left - right;
    case TokenType::SLASH:
        return left / right;
    case TokenType::STAR:
        return left * right;
    case TokenType::PLUS:
        return left + right;
    case TokenType::GREATER:
        return left > right;
    case TokenType::GREATER_EQUAL:
        return left >= right;
    case TokenType::LESS:
        return left < right;
    case TokenType::LESS_EQUAL:
        return left <= right;
    case TokenType::BANG_EQUAL:
        return left != right;
    case TokenType::EQUAL_EQUAL:
        return left == right;
    default:
      break;
  }

  std::cout << "Unreachable code reached in Interpreter::visit(Binary* expr) " << std::endl;
  return std::any();
}
