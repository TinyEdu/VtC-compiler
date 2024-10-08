// Interpreter.cpp
#include "Expression.h"
#include "Transpiler.h"
#include "Visitor.h"

#include "Callable.h"
#include "ClockCallable.h"
#include "FunctionCallable.h"
#include "Return.h"

#include "Interpreter.h"


Interpreter::Interpreter() { 
  environment = new Environment();
  // define a builtin clock function
  environment->define("clock", new ClockCallable());

}

Interpreter::~Interpreter() {}

void Interpreter::interpret(Expression* expr) {
  try {
    Expression* value = evaluate<Expression*>(expr);

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
  Expression* value = evaluate<Expression*>(expr->value);
  environment->assign(expr->name.lexeme, value);
  return value;
}

std::any Interpreter::visit(Binary* expr) {
  Literal* left = evaluate<Literal*>(expr->left);
  Literal* right = evaluate<Literal*>(expr->right);

  auto result = left->process(right, expr->op);

  return result;
}

std::any Interpreter::visit(Literal* expr) {
  return static_cast<Expression*>(expr);
}

std::any Interpreter::visit(Grouping* expr) {
  return evaluate(expr->expression);
}

std::any Interpreter::visit(Unary* expr) {
  Literal* right = evaluate<Literal*>(expr->right);

  switch (expr->op.type) {
    case TokenType::BANG:
    case TokenType::MINUS:
      return right->process(expr->op);
    default:
      break;
  }

  LOG << "Unreachable code reached in Interpreter::visit(Unary* expr) " << ENDL;
  return std::any();
}

std::any Interpreter::visit(Variable* expr) {
  // Note: orginal shouldn't be casted to Expression, might be a function 
  // return environment->lookup<Expression*>(expr->name.lexeme);
  return environment->lookup<Expression*>(expr->name.lexeme);
}

std::any Interpreter::visit(Logical* expr) {
  Expression* left = evaluate<Literal*>(expr->left);  
      // @TODO: should we cast it to Literal?

  if (expr->op.type == TokenType::OR) {
    if (left)
      return left;
  } else {
    if (!left)
      return left;
  }

  return evaluate(expr->right); // halo
}

std::any Interpreter::visit(Call* expr) {
  // look up the function
  std::string functionName = static_cast<Variable*>(expr->callee)->name.lexeme;
  Callable* function = environment->lookup<Callable*>(functionName);

  std::vector<Expression*> arguments;
  
  for (auto& argument : expr->arguments) {
    arguments.push_back(evaluate<Expression*>(argument));
  }

  // don't allow passing different amount of arguments then expected
  if (arguments.size() != function->arity()) {
    throw std::runtime_error("Expected " + std::to_string(function->arity()) + " arguments but got " + std::to_string(arguments.size()) + ".");
  }

  return function->call(this, arguments);
}

// ______________________________________________________________

std::any Interpreter::visit(IfStatement* stmt) {
  Expression* r = evaluate<Literal*>(stmt->condition);
  LiteralBool* lb;

  // check if is a LiteralBool
  if ((lb = dynamic_cast<LiteralBool*>(r))) {
    if (lb->value) {
      execute(stmt->thenBranch);
    } else if (stmt->elseBranch != nullptr) {
      execute(stmt->elseBranch);
    }
  } else {
    throw std::runtime_error("If statement condition must be possible to evaluate as a boolean");
  }

  return std::any();
}

std::any Interpreter::visit(ExpressionStatement* stmt) {
  evaluate(stmt->expression);
  return std::any();
}

std::any Interpreter::visit(PrintStatement* stmt) {
  std::stringstream ss;
  std::any li = evaluate(stmt->expression);
  Expression* lit = std::any_cast<Expression*>(li); // @TODO bad any cast

  // check with static_cast what type of literal we have, store it in auto r
  if (auto r = dynamic_cast<LiteralString*>(lit)) {
    ss << r->value;
  } else if (auto r = dynamic_cast<LiteralInt*>(lit)) {
    ss << r->value;
  } else if (auto r = dynamic_cast<LiteralBool*>(lit)) {
    if (r->value) {
      ss << "true";
    } else {
      ss << "false";
    }
  } else if (auto r = dynamic_cast<LiteralFloat*>(lit)) {
    ss << r->value;
  } else if (auto r = dynamic_cast<LiteralDouble*>(lit)) {
    ss << r->value;
  } else {
    ss << "Unknown type";
  }

  std::cout << "PRINT FUNCTION --> " << ss.str() << "\n";
  return std::any();
}

std::any Interpreter::visit(VarStatement* stmt) {
  Expression* value = nullptr;

  if (stmt->initializer != nullptr) {
    value = evaluate<Expression*>(stmt->initializer);
    environment->define(stmt->name.lexeme, value);
  } else {
    // if we have a variable declaration without an initializer
    // we should throw an error
    throw std::runtime_error("Variable declaration without an initializer");
  }

  return std::any();
}

std::any Interpreter::visit(BlockStatement* stmt) {
  executeBlock(stmt->statements, new Environment(environment->globalVariables));
  return std::any();
}

std::any Interpreter::visit(FunctionStatement* stmt) {
  FunctionCallable* function = new FunctionCallable(stmt);

  environment->define(stmt->name.lexeme, function);

  return std::any();
}

std::any Interpreter::visit(ClassStatement* stmt) {
  return std::any();
}

std::any Interpreter::visit(WhileStatement* stmt) {
  
  while (evaluate<LiteralBool*>(stmt->condition)->value) {
    execute(stmt->body);
  }

  return std::any();
}

std::any Interpreter::visit(ReturnStatement* stmt) {
  Literal* value = nullptr;

  if (stmt->value != nullptr) {
    value = evaluate<Literal*>(stmt->value);
  }

  throw Return(value);
}
