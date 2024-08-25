// Callable.h

#ifndef CALLABLE_H
#define CALLABLE_H

#include <any>
#include <vector>
#include <iostream>


class Interpreter;
class Expression;

class Callable {
 public:
  virtual int arity();
  virtual std::any call(Interpreter* interpreter, std::vector<Expression*> arguments);

  Callable() = default;
  ~Callable() = default;

  friend std::ostream& operator<<(std::ostream& os, const Callable& expr);
  friend std::ostream& operator<<(std::ostream& os, const Callable* expr);
};

#endif  // CALLABLE_H