// Callable.h

#ifndef CALLABLE_H
#define CALLABLE_H

#include <any>
#include <vector>

class Interpreter;
class Expression;

class Callable {
 public:
  virtual int arity();
  virtual std::any call(Interpreter* interpreter, std::vector<Expression*> arguments);
};

#endif  // CALLABLE_H