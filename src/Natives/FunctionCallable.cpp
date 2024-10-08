#include "FunctionCallable.h"

#include "Interpreter.h"
#include "ExpressionWorld.h"
#include "Environment.h"
#include "Statement.h"
#include "Return.h"

#include <iostream>

int FunctionCallable::arity() {
  return declaration->params.size();
}

std::any FunctionCallable::call(Interpreter* interpreter,
                                std::vector<Expression*> arguments) {
  
  Environment* environment = new Environment(interpreter->environment->globalVariables);

  for (int i = 0; i < declaration->params.size(); i++) {
    environment->define(declaration->params[i].lexeme, arguments[i]);
  }

  try {
    interpreter->executeBlock(declaration->body, environment);
  } catch (const Return& returnedValue) {
    std::any result = returnedValue.value;
    return result;
  }

  return std::any();
}

    std::ostream& operator<<(std::ostream& os, const FunctionCallable& expr) {
        os << "FunctionCallable - " << expr.declaration->name.lexeme;
        return os;
    }
    std::ostream& operator<<(std::ostream& os, const FunctionCallable* expr) {
        os << "FunctionCallable - " << expr->declaration->name.lexeme;
        return os;
    }