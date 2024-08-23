// Interpreter.cpp
#include "Expression.h"
#include "Transpiler.h"
#include "Visitor.h"

#include "Interpreter.h"

Interpreter::Interpreter() : environment(new Environment()) {}

Interpreter::~Interpreter() {}

void Interpreter::interpret(Expression* expr) {
  try {
    Expression* value = evaluate(expr);

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

Expression* Interpreter::evaluate(Expression* expr) {
  return std::any_cast<Expression*>(expr->accept(this));
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

void Interpreter::execute(Statement* stmt) {
  stmt->accept(this);
}

// ______________________________________________________________

std::any Interpreter::visit(Assign* expr) {
  Expression* value = evaluate(expr->value);
  environment->assign(expr->name.lexeme, value);
  return value;
}

std::any Interpreter::visit(Binary* expr) {
  Literal* left = static_cast<Literal*>(evaluate(expr->left));
  Literal* right = static_cast<Literal*>(evaluate(expr->right));

  left->process(right, expr->op);

  LOG << "Unreachable code reached in Interpreter::visit(B) \n";
  return std::any();
}

std::any Interpreter::visit(Literal* expr) {
  return static_cast<Expression*>(expr);
}

std::any Interpreter::visit(Grouping* expr) {
  return evaluate(expr->expression);
}

std::any Interpreter::visit(Unary* expr) {
  Literal* right = static_cast<Literal*>(evaluate(expr->right));

  switch (expr->op.type) {
    case TokenType::BANG:
      return right->process(expr->op);
    case TokenType::MINUS:
      return right->process(expr->op);
    default:
      break;
  }

  LOG << "Unreachable code reached in Interpreter::visit(Unary* expr) " << ENDL;
  return std::any();
}

std::any Interpreter::visit(Variable* expr) {
  return environment->lookup(expr->name.lexeme);
}

std::any Interpreter::visit(Logical* expr) {
  Expression* left =
      evaluate(expr->left);  // @TODO: should we cast it to Literal?

  if (expr->op.type == TokenType::OR) {
    if (left)
      return left;
  } else {
    if (!left)
      return left;
  }

  return evaluate(expr->right);
}

// ______________________________________________________________

std::any Interpreter::visit(IfStatement* stmt) {
  bool isTrutrhy = evaluate(stmt->condition);
  if (isTrutrhy) {
    execute(stmt->thenBranch);
  } else if (stmt->elseBranch != nullptr) {
    execute(stmt->elseBranch);
  }

  return std::any();
}

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
  } else {
    // if we have a variable declaration without an initializer
    // we should throw an error
    throw std::runtime_error("Variable declaration without an initializer");
  }

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

std::any Interpreter::visit(WhileStatement* stmt) {
  while (evaluate(stmt->condition)) {
    execute(stmt->body);
  }

  return std::any();
}
