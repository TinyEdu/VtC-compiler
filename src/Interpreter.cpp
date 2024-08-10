#include "Expression.h"
#include "Visitor.h"

#include "Interpreter.h"

Interpreter::Interpreter() {}

void Interpreter::interpret(Expression* expr) {
    try {
        Literal* value = evaluate(expr);

        // Print the expression
        LOG << value << ENDL;    

    } catch (std::runtime_error& e) {
        std::cerr << e.what() << ENDL;
    }
}


std::any Interpreter::visit(Literal* expr) {  // @TODO - do I want to return this for sure?
    LOG << "Visit Literal\n";
    return expr;
}


std::any Interpreter::visit(Grouping* expr) {
    return evaluate(expr->expression);
}


Literal* Interpreter::evaluate(Expression* expr) {
    return std::any_cast<Literal*>(expr->accept(this));
}


std::any Interpreter::visit(Unary* expr) {
    LOG << "Visit Unary\n";
    Literal* right = evaluate(expr->right);

    switch (expr->op.type) {
        case TokenType::BANG:
            // return !isTruthy(right);
            return !*right;
        case TokenType::MINUS:
            // return -std::any_cast<double>(right);
            return -*right;
        default:
            break;
    }

    LOG << "Unreachable code reached in Interpreter::visit(Unary* expr) " << ENDL;
    return std::any();
}


Interpreter::~Interpreter() {}


std::any Interpreter::visit(Binary* expr) {
    LOG << "Visit Binary\n";
  Literal* left = evaluate(expr->left);
  Literal* right = evaluate(expr->right);

  switch (expr->op.type) {
    case TokenType::MINUS:
      return *left - *right;
    case TokenType::SLASH:
        return *left / *right;
    case TokenType::STAR:
        return *left * *right;
    case TokenType::PLUS:
        return *left + *right;
    case TokenType::GREATER:
        return *left > *right;
    case TokenType::GREATER_EQUAL:
        return *left >= *right;
    case TokenType::LESS:
        return *left < *right;
    case TokenType::LESS_EQUAL:
        return *left <= *right;
    case TokenType::BANG_EQUAL:
        return *left != *right;
    case TokenType::EQUAL_EQUAL:
        return *left == *right;
    default:
      break;
  }

  LOG << "Unreachable code reached in Interpreter::visit(Binary* expr) " << ENDL;
  return std::any();
}
