// Interpreter.cpp
#include "Expression.h"
#include "Transpiler.h"
#include "Visitor.h"

#include "Interpreter.h"

Interpreter::Interpreter() : environment(new Environment()){}

Interpreter::~Interpreter() {}

void Interpreter::interpret(Expression* expr) {
  try {
    Literal* value = evaluate(expr);

    // Print the expression
    LOG << value << ENDL;

  } catch (std::runtime_error& e) {
    Transpiler::runtimeError(e);
  }
}

void Interpreter::interpret(std::vector<Statement*> stmt) {
  try {
    for (auto& statement : stmt) {
      statement->accept(this);
    }
  } catch (const std::exception& e) {
    CRIT << e.what() << ENDL;
  }
}

Literal* Interpreter::evaluate(Expression* expr) {
  return std::any_cast<Literal*>(expr->accept(this));
}

void Interpreter::executeBlock(std::vector<Statement*> stmt, Environment* env) {
  Environment* previous = environment;
  /*
  Manually changing and restoring a mutable environment field feels inelegant. Another classic approach is to explicitly pass the environment as a parameter to each visit method. To “change” the environment, you pass a different one as you recurse down the tree. You don’t have to restore the old one, since the new one lives on the Java stack and is implicitly discarded when the interpreter returns from the block’s visit method.

  ~ https://craftinginterpreters.com/statements-and-state.html 
  */
  try {
    environment = env;

    // Execute the block
    for (auto& statement : stmt) {
      statement->accept(this);
    }

  } catch (const std::exception& e) {
    this->environment = previous;
    CRIT << e.what() << ENDL;
  }

  environment = previous;
}

// ______________________________________________________________

std::any Interpreter::visit(Assign* expr) {
  Literal* value = evaluate(expr->value);
  environment->assign(expr->name.lexeme, value);
  return value;
}

std::any Interpreter::visit(Binary* expr) {
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

  LOG << "Unreachable code reached in Interpreter::visit(Binary* expr) "
      << ENDL;
  return std::any();
}

std::any Interpreter::visit(Literal* expr) {
  return expr;
}

std::any Interpreter::visit(Grouping* expr) {
  return evaluate(expr->expression);
}

std::any Interpreter::visit(Unary* expr) {
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

std::any Interpreter::visit(Variable* expr) {
  return environment->lookup(expr->name.lexeme);
}

// ______________________________________________________________

std::any Interpreter::visit(ExpressionStatement* stmt) {
  evaluate(stmt->expression);
  return std::any();
}

std::any Interpreter::visit(PrintStatement* stmt) {
  std::cout << "PRINT FUNCTION: " << evaluate(stmt->expression) << "\n";
  return std::any();
}

std::any Interpreter::visit(VarStatement* stmt) {
  Expression* value = nullptr;

  if (stmt->initializer != nullptr) {
    value = evaluate(stmt->initializer);
    environment->define(stmt->name.lexeme, value);
  }
  
  // if we have a variable declaration without an initializer
  // we should throw an error
  throw std::runtime_error("Variable declaration without an initializer");
  
  return std::any();
}

std::any Interpreter::visit(BlockStatement* stmt) {
  executeBlock(stmt->statements, new Environment(environment));
  return std::any();
}

std::any Interpreter::visit(FunctionStatement* stmt) {
  return std::any();
}

std::any Interpreter::visit(ClassStatement* stmt) {
  return std::any();
}
