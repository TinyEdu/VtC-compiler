#include "OperationsDispatcher.h"

Literal* OperationsDispatcher::add(LiteralInt* left, LiteralInt* right) {
  return new LiteralInt(left->value + right->value);
}
Literal* OperationsDispatcher::add(LiteralInt* left, LiteralFloat* right) {
  return new LiteralFloat(left->value + right->value);
}
Literal* OperationsDispatcher::add(LiteralInt* left, LiteralString* right) {
  throw std::runtime_error(
      "Illegal operation[add] LiteralInt | LiteralString!");
  return nullptr;
}
Literal* OperationsDispatcher::add(LiteralInt* left, LiteralBool* right) {
  return new LiteralInt(left->value + right->value);
}
Literal* OperationsDispatcher::add(LiteralInt* left, LiteralDouble* right) {
  return new LiteralDouble(left->value + right->value);
}
Literal* OperationsDispatcher::add(LiteralFloat* left, LiteralInt* right) {
  return new LiteralFloat(left->value + right->value);
}
Literal* OperationsDispatcher::add(LiteralFloat* left, LiteralFloat* right) {
  return new LiteralFloat(left->value + right->value);
}
Literal* OperationsDispatcher::add(LiteralFloat* left, LiteralString* right) {
  throw std::runtime_error(
      "Illegal operation[add] LiteralFloat | LiteralString!");
  return nullptr;
}
Literal* OperationsDispatcher::add(LiteralFloat* left, LiteralBool* right) {
  return new LiteralFloat(left->value + right->value);
}
Literal* OperationsDispatcher::add(LiteralFloat* left, LiteralDouble* right) {
  return new LiteralDouble(left->value + right->value);
}
Literal* OperationsDispatcher::add(LiteralString* left, LiteralInt* right) {
  throw std::runtime_error(
      "Illegal operation[add] LiteralString | LiteralInt!");
  return nullptr;
}
Literal* OperationsDispatcher::add(LiteralString* left, LiteralFloat* right) {
  throw std::runtime_error(
      "Illegal operation[add] LiteralString | LiteralFloat!");
  return nullptr;
}
Literal* OperationsDispatcher::add(LiteralString* left, LiteralString* right) {
  return new LiteralString(left->value + right->value);
}
Literal* OperationsDispatcher::add(LiteralString* left, LiteralBool* right) {
  throw std::runtime_error(
      "Illegal operation[add] LiteralString | LiteralBool!");
  return nullptr;
}
Literal* OperationsDispatcher::add(LiteralString* left, LiteralDouble* right) {
  throw std::runtime_error(
      "Illegal operation[add] LiteralString | LiteralDouble!");
  return nullptr;
}
Literal* OperationsDispatcher::add(LiteralBool* left, LiteralInt* right) {
  return new LiteralInt(left->value + right->value);
}
Literal* OperationsDispatcher::add(LiteralBool* left, LiteralFloat* right) {
  return new LiteralFloat(left->value + right->value);
}
Literal* OperationsDispatcher::add(LiteralBool* left, LiteralString* right) {
  throw std::runtime_error(
      "Illegal operation[add] LiteralBool | LiteralString!");
  return nullptr;
}
Literal* OperationsDispatcher::add(LiteralBool* left, LiteralBool* right) {
  return new LiteralInt(left->value + right->value);
}
Literal* OperationsDispatcher::add(LiteralBool* left, LiteralDouble* right) {
  return new LiteralDouble(left->value + right->value);
}
Literal* OperationsDispatcher::add(LiteralDouble* left, LiteralInt* right) {
  return new LiteralDouble(left->value + right->value);
}
Literal* OperationsDispatcher::add(LiteralDouble* left, LiteralFloat* right) {
  return new LiteralDouble(left->value + right->value);
}
Literal* OperationsDispatcher::add(LiteralDouble* left, LiteralString* right) {
  throw std::runtime_error(
      "Illegal operation[add] LiteralDouble | LiteralString!");
  return nullptr;
}
Literal* OperationsDispatcher::add(LiteralDouble* left, LiteralBool* right) {
  return new LiteralDouble(left->value + right->value);
}
Literal* OperationsDispatcher::add(LiteralDouble* left, LiteralDouble* right) {
  return new LiteralDouble(left->value + right->value);
}
Literal* OperationsDispatcher::subtract(LiteralInt* left, LiteralInt* right) {
  return new LiteralInt(left->value - right->value);
}
Literal* OperationsDispatcher::subtract(LiteralInt* left, LiteralFloat* right) {
  return new LiteralFloat(left->value - right->value);
}
Literal* OperationsDispatcher::subtract(LiteralInt* left,
                                        LiteralString* right) {
  throw std::runtime_error(
      "Illegal operation[subtract] LiteralInt | LiteralString!");
  return nullptr;
}
Literal* OperationsDispatcher::subtract(LiteralInt* left, LiteralBool* right) {
  return new LiteralInt(left->value - right->value);
}
Literal* OperationsDispatcher::subtract(LiteralInt* left,
                                        LiteralDouble* right) {
  return new LiteralDouble(left->value - right->value);
}
Literal* OperationsDispatcher::subtract(LiteralFloat* left, LiteralInt* right) {
  return new LiteralFloat(left->value - right->value);
}
Literal* OperationsDispatcher::subtract(LiteralFloat* left,
                                        LiteralFloat* right) {
  return new LiteralFloat(left->value - right->value);
}
Literal* OperationsDispatcher::subtract(LiteralFloat* left,
                                        LiteralString* right) {
  throw std::runtime_error(
      "Illegal operation[subtract] LiteralFloat | LiteralString!");
  return nullptr;
}
Literal* OperationsDispatcher::subtract(LiteralFloat* left,
                                        LiteralBool* right) {
  return new LiteralFloat(left->value - right->value);
}
Literal* OperationsDispatcher::subtract(LiteralFloat* left,
                                        LiteralDouble* right) {
  return new LiteralDouble(left->value - right->value);
}
Literal* OperationsDispatcher::subtract(LiteralString* left,
                                        LiteralInt* right) {
  throw std::runtime_error(
      "Illegal operation[subtract] LiteralString | LiteralInt!");
  return nullptr;
}
Literal* OperationsDispatcher::subtract(LiteralString* left,
                                        LiteralFloat* right) {
  throw std::runtime_error(
      "Illegal operation[subtract] LiteralString | LiteralFloat!");
  return nullptr;
}
Literal* OperationsDispatcher::subtract(LiteralString* left,
                                        LiteralString* right) {
  return new LiteralString(left->value - right->value);
}
Literal* OperationsDispatcher::subtract(LiteralString* left,
                                        LiteralBool* right) {
  throw std::runtime_error(
      "Illegal operation[subtract] LiteralString | LiteralBool!");
  return nullptr;
}
Literal* OperationsDispatcher::subtract(LiteralString* left,
                                        LiteralDouble* right) {
  throw std::runtime_error(
      "Illegal operation[subtract] LiteralString | LiteralDouble!");
  return nullptr;
}
Literal* OperationsDispatcher::subtract(LiteralBool* left, LiteralInt* right) {
  return new LiteralInt(left->value - right->value);
}
Literal* OperationsDispatcher::subtract(LiteralBool* left,
                                        LiteralFloat* right) {
  return new LiteralFloat(left->value - right->value);
}
Literal* OperationsDispatcher::subtract(LiteralBool* left,
                                        LiteralString* right) {
  throw std::runtime_error(
      "Illegal operation[subtract] LiteralBool | LiteralString!");
  return nullptr;
}
Literal* OperationsDispatcher::subtract(LiteralBool* left, LiteralBool* right) {
  return new LiteralInt(left->value - right->value);
}
Literal* OperationsDispatcher::subtract(LiteralBool* left,
                                        LiteralDouble* right) {
  return new LiteralDouble(left->value - right->value);
}
Literal* OperationsDispatcher::subtract(LiteralDouble* left,
                                        LiteralInt* right) {
  return new LiteralDouble(left->value - right->value);
}
Literal* OperationsDispatcher::subtract(LiteralDouble* left,
                                        LiteralFloat* right) {
  return new LiteralDouble(left->value - right->value);
}
Literal* OperationsDispatcher::subtract(LiteralDouble* left,
                                        LiteralString* right) {
  throw std::runtime_error(
      "Illegal operation[subtract] LiteralDouble | LiteralString!");
  return nullptr;
}
Literal* OperationsDispatcher::subtract(LiteralDouble* left,
                                        LiteralBool* right) {
  return new LiteralDouble(left->value - right->value);
}
Literal* OperationsDispatcher::subtract(LiteralDouble* left,
                                        LiteralDouble* right) {
  return new LiteralDouble(left->value - right->value);
}
Literal* OperationsDispatcher::multiply(LiteralInt* left, LiteralInt* right) {
  return new LiteralInt(left->value * right->value);
}
Literal* OperationsDispatcher::multiply(LiteralInt* left, LiteralFloat* right) {
  return new LiteralFloat(left->value * right->value);
}
Literal* OperationsDispatcher::multiply(LiteralInt* left,
                                        LiteralString* right) {
  throw std::runtime_error(
      "Illegal operation[multiply] LiteralInt | LiteralString!");
  return nullptr;
}
Literal* OperationsDispatcher::multiply(LiteralInt* left, LiteralBool* right) {
  return new LiteralInt(left->value * right->value);
}
Literal* OperationsDispatcher::multiply(LiteralInt* left,
                                        LiteralDouble* right) {
  return new LiteralDouble(left->value * right->value);
}
Literal* OperationsDispatcher::multiply(LiteralFloat* left, LiteralInt* right) {
  return new LiteralFloat(left->value * right->value);
}
Literal* OperationsDispatcher::multiply(LiteralFloat* left,
                                        LiteralFloat* right) {
  return new LiteralFloat(left->value * right->value);
}
Literal* OperationsDispatcher::multiply(LiteralFloat* left,
                                        LiteralString* right) {
  throw std::runtime_error(
      "Illegal operation[multiply] LiteralFloat | LiteralString!");
  return nullptr;
}
Literal* OperationsDispatcher::multiply(LiteralFloat* left,
                                        LiteralBool* right) {
  return new LiteralFloat(left->value * right->value);
}
Literal* OperationsDispatcher::multiply(LiteralFloat* left,
                                        LiteralDouble* right) {
  return new LiteralDouble(left->value * right->value);
}
Literal* OperationsDispatcher::multiply(LiteralString* left,
                                        LiteralInt* right) {
  throw std::runtime_error(
      "Illegal operation[multiply] LiteralString | LiteralInt!");
  return nullptr;
}
Literal* OperationsDispatcher::multiply(LiteralString* left,
                                        LiteralFloat* right) {
  throw std::runtime_error(
      "Illegal operation[multiply] LiteralString | LiteralFloat!");
  return nullptr;
}
Literal* OperationsDispatcher::multiply(LiteralString* left,
                                        LiteralString* right) {
  return new LiteralString(left->value * right->value);
}
Literal* OperationsDispatcher::multiply(LiteralString* left,
                                        LiteralBool* right) {
  throw std::runtime_error(
      "Illegal operation[multiply] LiteralString | LiteralBool!");
  return nullptr;
}
Literal* OperationsDispatcher::multiply(LiteralString* left,
                                        LiteralDouble* right) {
  throw std::runtime_error(
      "Illegal operation[multiply] LiteralString | LiteralDouble!");
  return nullptr;
}
Literal* OperationsDispatcher::multiply(LiteralBool* left, LiteralInt* right) {
  return new LiteralInt(left->value * right->value);
}
Literal* OperationsDispatcher::multiply(LiteralBool* left,
                                        LiteralFloat* right) {
  return new LiteralFloat(left->value * right->value);
}
Literal* OperationsDispatcher::multiply(LiteralBool* left,
                                        LiteralString* right) {
  throw std::runtime_error(
      "Illegal operation[multiply] LiteralBool | LiteralString!");
  return nullptr;
}
Literal* OperationsDispatcher::multiply(LiteralBool* left, LiteralBool* right) {
  return new LiteralInt(left->value * right->value);
}
Literal* OperationsDispatcher::multiply(LiteralBool* left,
                                        LiteralDouble* right) {
  return new LiteralDouble(left->value * right->value);
}
Literal* OperationsDispatcher::multiply(LiteralDouble* left,
                                        LiteralInt* right) {
  return new LiteralDouble(left->value * right->value);
}
Literal* OperationsDispatcher::multiply(LiteralDouble* left,
                                        LiteralFloat* right) {
  return new LiteralDouble(left->value * right->value);
}
Literal* OperationsDispatcher::multiply(LiteralDouble* left,
                                        LiteralString* right) {
  throw std::runtime_error(
      "Illegal operation[multiply] LiteralDouble | LiteralString!");
  return nullptr;
}
Literal* OperationsDispatcher::multiply(LiteralDouble* left,
                                        LiteralBool* right) {
  return new LiteralDouble(left->value * right->value);
}
Literal* OperationsDispatcher::multiply(LiteralDouble* left,
                                        LiteralDouble* right) {
  return new LiteralDouble(left->value * right->value);
}
Literal* OperationsDispatcher::divide(LiteralInt* left, LiteralInt* right) {
  return new LiteralInt(left->value / right->value);
}
Literal* OperationsDispatcher::divide(LiteralInt* left, LiteralFloat* right) {
  return new LiteralFloat(left->value / right->value);
}
Literal* OperationsDispatcher::divide(LiteralInt* left, LiteralString* right) {
  throw std::runtime_error(
      "Illegal operation[divide] LiteralInt | LiteralString!");
  return nullptr;
}
Literal* OperationsDispatcher::divide(LiteralInt* left, LiteralBool* right) {
  return new LiteralInt(left->value / right->value);
}
Literal* OperationsDispatcher::divide(LiteralInt* left, LiteralDouble* right) {
  return new LiteralDouble(left->value / right->value);
}
Literal* OperationsDispatcher::divide(LiteralFloat* left, LiteralInt* right) {
  return new LiteralFloat(left->value / right->value);
}
Literal* OperationsDispatcher::divide(LiteralFloat* left, LiteralFloat* right) {
  return new LiteralFloat(left->value / right->value);
}
Literal* OperationsDispatcher::divide(LiteralFloat* left,
                                      LiteralString* right) {
  throw std::runtime_error(
      "Illegal operation[divide] LiteralFloat | LiteralString!");
  return nullptr;
}
Literal* OperationsDispatcher::divide(LiteralFloat* left, LiteralBool* right) {
  return new LiteralFloat(left->value / right->value);
}
Literal* OperationsDispatcher::divide(LiteralFloat* left,
                                      LiteralDouble* right) {
  return new LiteralDouble(left->value / right->value);
}
Literal* OperationsDispatcher::divide(LiteralString* left, LiteralInt* right) {
  throw std::runtime_error(
      "Illegal operation[divide] LiteralString | LiteralInt!");
  return nullptr;
}
Literal* OperationsDispatcher::divide(LiteralString* left,
                                      LiteralFloat* right) {
  throw std::runtime_error(
      "Illegal operation[divide] LiteralString | LiteralFloat!");
  return nullptr;
}
Literal* OperationsDispatcher::divide(LiteralString* left,
                                      LiteralString* right) {
  return new LiteralString(left->value / right->value);
}
Literal* OperationsDispatcher::divide(LiteralString* left, LiteralBool* right) {
  throw std::runtime_error(
      "Illegal operation[divide] LiteralString | LiteralBool!");
  return nullptr;
}
Literal* OperationsDispatcher::divide(LiteralString* left,
                                      LiteralDouble* right) {
  throw std::runtime_error(
      "Illegal operation[divide] LiteralString | LiteralDouble!");
  return nullptr;
}
Literal* OperationsDispatcher::divide(LiteralBool* left, LiteralInt* right) {
  return new LiteralInt(left->value / right->value);
}
Literal* OperationsDispatcher::divide(LiteralBool* left, LiteralFloat* right) {
  return new LiteralFloat(left->value / right->value);
}
Literal* OperationsDispatcher::divide(LiteralBool* left, LiteralString* right) {
  throw std::runtime_error(
      "Illegal operation[divide] LiteralBool | LiteralString!");
  return nullptr;
}
Literal* OperationsDispatcher::divide(LiteralBool* left, LiteralBool* right) {
  return new LiteralInt(left->value / right->value);
}
Literal* OperationsDispatcher::divide(LiteralBool* left, LiteralDouble* right) {
  return new LiteralDouble(left->value / right->value);
}
Literal* OperationsDispatcher::divide(LiteralDouble* left, LiteralInt* right) {
  return new LiteralDouble(left->value / right->value);
}
Literal* OperationsDispatcher::divide(LiteralDouble* left,
                                      LiteralFloat* right) {
  return new LiteralDouble(left->value / right->value);
}
Literal* OperationsDispatcher::divide(LiteralDouble* left,
                                      LiteralString* right) {
  throw std::runtime_error(
      "Illegal operation[divide] LiteralDouble | LiteralString!");
  return nullptr;
}
Literal* OperationsDispatcher::divide(LiteralDouble* left, LiteralBool* right) {
  return new LiteralDouble(left->value / right->value);
}
Literal* OperationsDispatcher::divide(LiteralDouble* left,
                                      LiteralDouble* right) {
  return new LiteralDouble(left->value / right->value);
}
Literal* OperationsDispatcher::modulo(LiteralInt* left, LiteralInt* right) {
  return new LiteralInt(left->value % right->value);
}
Literal* OperationsDispatcher::modulo(LiteralInt* left, LiteralFloat* right) {
  return new LiteralFloat(left->value % right->value);
}
Literal* OperationsDispatcher::modulo(LiteralInt* left, LiteralString* right) {
  throw std::runtime_error(
      "Illegal operation[modulo] LiteralInt | LiteralString!");
  return nullptr;
}
Literal* OperationsDispatcher::modulo(LiteralInt* left, LiteralBool* right) {
  return new LiteralInt(left->value % right->value);
}
Literal* OperationsDispatcher::modulo(LiteralInt* left, LiteralDouble* right) {
  return new LiteralDouble(left->value % right->value);
}
Literal* OperationsDispatcher::modulo(LiteralFloat* left, LiteralInt* right) {
  return new LiteralFloat(left->value % right->value);
}
Literal* OperationsDispatcher::modulo(LiteralFloat* left, LiteralFloat* right) {
  return new LiteralFloat(left->value % right->value);
}
Literal* OperationsDispatcher::modulo(LiteralFloat* left,
                                      LiteralString* right) {
  throw std::runtime_error(
      "Illegal operation[modulo] LiteralFloat | LiteralString!");
  return nullptr;
}
Literal* OperationsDispatcher::modulo(LiteralFloat* left, LiteralBool* right) {
  return new LiteralFloat(left->value % right->value);
}
Literal* OperationsDispatcher::modulo(LiteralFloat* left,
                                      LiteralDouble* right) {
  return new LiteralDouble(left->value % right->value);
}
Literal* OperationsDispatcher::modulo(LiteralString* left, LiteralInt* right) {
  throw std::runtime_error(
      "Illegal operation[modulo] LiteralString | LiteralInt!");
  return nullptr;
}
Literal* OperationsDispatcher::modulo(LiteralString* left,
                                      LiteralFloat* right) {
  throw std::runtime_error(
      "Illegal operation[modulo] LiteralString | LiteralFloat!");
  return nullptr;
}
Literal* OperationsDispatcher::modulo(LiteralString* left,
                                      LiteralString* right) {
  throw std::runtime_error(
      "Illegal operation[modulo] LiteralString | LiteralString!");
  return nullptr;
}

Literal* OperationsDispatcher::modulo(LiteralString* left, LiteralBool* right) {
  throw std::runtime_error(
      "Illegal operation[modulo] LiteralString | LiteralBool!");
  return nullptr;
}
Literal* OperationsDispatcher::modulo(LiteralString* left,
                                      LiteralDouble* right) {
  throw std::runtime_error(
      "Illegal operation[modulo] LiteralString | LiteralDouble!");
  return nullptr;
}
Literal* OperationsDispatcher::modulo(LiteralBool* left, LiteralInt* right) {
  return new LiteralInt(left->value % right->value);
}
Literal* OperationsDispatcher::modulo(LiteralBool* left, LiteralFloat* right) {
  return new LiteralFloat(left->value % right->value);
}
Literal* OperationsDispatcher::modulo(LiteralBool* left, LiteralString* right) {
  throw std::runtime_error(
      "Illegal operation[modulo] LiteralBool | LiteralString!");
  return nullptr;
}
Literal* OperationsDispatcher::modulo(LiteralBool* left, LiteralBool* right) {
  return new LiteralInt(left->value % right->value);
}
Literal* OperationsDispatcher::modulo(LiteralBool* left, LiteralDouble* right) {
  return new LiteralDouble(left->value % right->value);
}
Literal* OperationsDispatcher::modulo(LiteralDouble* left, LiteralInt* right) {
  return new LiteralDouble(left->value % right->value);
}
Literal* OperationsDispatcher::modulo(LiteralDouble* left,
                                      LiteralFloat* right) {
  return new LiteralDouble(left->value % right->value);
}
Literal* OperationsDispatcher::modulo(LiteralDouble* left,
                                      LiteralString* right) {
  throw std::runtime_error(
      "Illegal operation[modulo] LiteralDouble | LiteralString!");
  return nullptr;
}
Literal* OperationsDispatcher::modulo(LiteralDouble* left, LiteralBool* right) {
  return new LiteralDouble(left->value % right->value);
}
Literal* OperationsDispatcher::modulo(LiteralDouble* left,
                                      LiteralDouble* right) {
  return new LiteralDouble(left->value % right->value);
}
