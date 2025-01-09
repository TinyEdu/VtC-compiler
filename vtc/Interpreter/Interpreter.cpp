//
// Created by nikod on 09/01/2025.
//

#include "Interpreter.h"
#include <any>
#include <iostream>
#include "LogManager/LogManager.h"
#include "Token/Token.h"
#include "Compiler/Compiler.h"

#include "Callable/Callable.h"
#include "Callable/Return.h"
#include "Callable/Natives/ClockCallable.h"
#include "Callable/Natives/FunctionCallable.h"

#include "ArityMismatchException.h"
#include "NonBooleanConditionException.h"
#include "MissingInitializerException.h"

Interpreter::Interpreter()
{
  environment = new Environment();

  // define a builtin clock function
  environment->define("clock", new ClockCallable());
}

Interpreter::~Interpreter() = default;

std::any Interpreter::evaluate(Expression* statement)
{
  return statement->accept(this);
}

void Interpreter::interpret(Expression* expression)
{
  try
  {
    auto* value = evaluate<Expression*>(expression);

    LogManager::log() << value;
  }
  catch (std::runtime_error& e)
  {
    Compiler::runtimeError(e);
  }
}

void Interpreter::interpret(const std::vector<std::unique_ptr<Statement>>& statements)
{
  try
  {
    for (auto& statement : statements)
    {
      statement->accept(this);
    }
  }
  catch (std::exception& e)
  {
    LogManager::crit() << e.what();
  }
}


void Interpreter::execute(const std::vector<Statement*>& statements, Environment* env)
{
  Environment* previous = environment;
  /*
  Manually changing and restoring a mutable environment field feels inelegant.
  Another classic approach is to explicitly pass the environment as a parameter to each visit method.
  To “change” the environment, you pass a different one as you recurse down the tree.
  You don’t have to restore the old one, since the new one lives on the Java stack and
  is implicitly discarded when the interpreter returns from the block’s visit method.

  ~ https://craftinginterpreters.com/statements-and-state.html
  */

  try
  {
    environment = env;

    // Execute the block
    for (auto& statement : statements)
    {
      statement->accept(this);
    }
  }
  catch (const std::exception& e)
  {
    this->environment = previous;
    LogManager::crit() << e.what();
  }

  environment = previous;
}

void Interpreter::execute(Statement* statement)
{
  statement->accept(this);
}

// ______________________________________________________________

std::any Interpreter::visit(Assign* expression)
{
  auto value = evaluate<Expression*>(expression->value);
  environment->assign(expression->name.lexeme, value);
  return value;
}

std::any Interpreter::visit(Binary* expression)
{
  const auto left = evaluate<Literal*>(expression->left);
  const auto right = evaluate<Literal*>(expression->right);

  auto result = left->process(right, expression->op);

  return result;
}

std::any Interpreter::visit(Literal* expression)
{
  // @TODO: ??? return static_cast<Expression*>(expression);
  return expression;
}

std::any Interpreter::visit(Grouping* expression)
{
  return evaluate(expression->expression);
}

std::any Interpreter::visit(Unary* expression)
{
  const auto right = evaluate<Literal*>(expression->right);

  switch (expression->op.type)
  {
  case TokenType::BANG:
  case TokenType::MINUS:
    return right->process(expression->op);
  default:
    break;
  }

  LogManager::log() << "Unreachable code reached in Interpreter::visit(Unary* expr) ";
  return {};
}

std::any Interpreter::visit(Variable* expression)
{
  // @TODO: ??? Note: orginal shouldn't be casted to Expression, might be a function
  return environment->lookup<Expression*>(expression->name.lexeme);
}

std::any Interpreter::visit(Logical* expression)
{
  const auto left = evaluate<Literal*>(expression->left);
  // @TODO: should we cast it to Literal?

  if (expression->op.type == TokenType::OR)
  {
    if (left)
    {
      return left;
    }
  }
  else
  {
    if (!left)
    {
      return left;
    }
  }

  // @TODO: ??? co to za komentarz
  return evaluate(expression->right); // halo
}

std::any Interpreter::visit(Call* expression)
{
  // Look up the function
  const std::string functionName = dynamic_cast<Variable*>(expression->callee)->name.lexeme;
  const auto function = environment->lookup<Callable*>(functionName);

  std::vector<Expression*> arguments;

  for (const auto& argument : expression->arguments)
  {
    arguments.push_back(evaluate<Expression*>(argument));
  }

  // Validate argument count
  if (arguments.size() != function->arity())
  {
    throw ArityMismatchException(
        std::format("Expected {} arguments but got {}.", function->arity(), arguments.size())
    );
  }

  return function->call(this, arguments);
}

std::any Interpreter::visit(IfStatement* statement)
{
  Expression* r = evaluate<Literal*>(statement->condition);

  // check if is a LiteralBool
  if (const auto lb = dynamic_cast<LiteralBool*>(r))
  {
    if (lb->value)
    {
      execute(statement->thenBranch);
    }
    else if (statement->elseBranch != nullptr)
    {
      execute(statement->elseBranch);
    }
  }
  else
  {
    throw NonBooleanConditionException("If statement condition must be possible to evaluate as a boolean.");
  }

  return {};
}

std::any Interpreter::visit(ExpressionStatement* statement)
{
  evaluate(statement->expression);

  return {};
}

std::any Interpreter::visit(PrintStatement* statement)
{
  std::stringstream ss;
  const std::any li = evaluate(statement->expression);

  // @TODO: ??? comment - bad any cast
  const auto lit = std::any_cast<Expression*>(li);

  if (const auto literal_string = dynamic_cast<LiteralString*>(lit))
  {
    ss << literal_string->value;
  }
  else if (const auto literal_int = dynamic_cast<LiteralInt*>(lit))
  {
    ss << literal_int->value;
  }
  else if (const auto literal_bool = dynamic_cast<LiteralBool*>(lit))
  {
    if (literal_bool->value)
    {
      ss << "true";
    }
    else
    {
      ss << "false";
    }
  }
  else if (const auto literal_float = dynamic_cast<LiteralFloat*>(lit))
  {
    ss << literal_float->value;
  }
  else if (const auto literal_double = dynamic_cast<LiteralDouble*>(lit))
  {
    ss << literal_double->value;
  }
  else
  {
    ss << "Unknown type";
  }

  std::cout << "PRINT FUNCTION --> " << ss.str() << "\n";
  return {};
}

std::any Interpreter::visit(VarStatement* statement)
{
  if (statement->initializer != nullptr)
  {
    Expression* value = nullptr;
    value = evaluate<Expression*>(statement->initializer);
    environment->define(statement->name.lexeme, value);
  }
  else
  {
    throw MissingInitializerException("Variable declaration without an initializer");
  }

  return {};
}

std::any Interpreter::visit(BlockStatement* statement)
{
  execute(statement->statements, new Environment(environment->globalVariables));

  return {};
}

std::any Interpreter::visit(FunctionStatement* statement)
{
  const auto function = new FunctionCallable(statement);

  environment->define(statement->name.lexeme, function);

  return {};
}

std::any Interpreter::visit(ClassStatement* statement)
{
  return {};
}

std::any Interpreter::visit(WhileStatement* statement)
{
  while (evaluate<LiteralBool*>(statement->condition)->value)
  {
    execute(statement->body);
  }

  return {};
}

std::any Interpreter::visit(ReturnStatement* statement)
{
  Literal* value = nullptr;

  if (statement->value != nullptr)
  {
    value = evaluate<Literal*>(statement->value);
  }

  throw Return(value);
}
