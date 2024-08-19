// OperationsDispatcher.h

#ifndef OPERATIONS_DISPATCHER_H
#define OPERATIONS_DISPATCHER_H

#include "ExpressionWorld.h"

class OperationsDispatcher {
 public:
  template <typename T1, typename T2>
  Expression* dispatch(T1 left, T2 right, Token token) {
    switch (token.type) {
      case TokenType::PLUS:
        add(left, right);
        break;
        // ...
      default:
        break;
    }
  }

  // Helper template to call the reversed addition if the direct one doesn't exist
  template <typename T1, typename T2>
  Expression* add(T1* left, T2* right) {
    return add_impl(left, right, std::is_same<T1, T2>());
  }

  // Every unique possible combination of dispatches for literals
  Literal* add(LiteralInt* left, LiteralInt* right);
  Literal* add(LiteralInt* left, LiteralFloat* right);
  Literal* add(LiteralInt* left, LiteralString* right);
  Literal* add(LiteralInt* left, LiteralBool* right);
  Literal* add(LiteralInt* left, LiteralDouble* right);
  Literal* add(LiteralFloat* left, LiteralInt* right);
  Literal* add(LiteralFloat* left, LiteralFloat* right);
  Literal* add(LiteralFloat* left, LiteralString* right);
  Literal* add(LiteralFloat* left, LiteralBool* right);
  Literal* add(LiteralFloat* left, LiteralDouble* right);
  Literal* add(LiteralString* left, LiteralInt* right);
  Literal* add(LiteralString* left, LiteralFloat* right);
  Literal* add(LiteralString* left, LiteralString* right);
  Literal* add(LiteralString* left, LiteralBool* right);
  Literal* add(LiteralString* left, LiteralDouble* right);
  Literal* add(LiteralBool* left, LiteralInt* right);
  Literal* add(LiteralBool* left, LiteralFloat* right);
  Literal* add(LiteralBool* left, LiteralString* right);
  Literal* add(LiteralBool* left, LiteralBool* right);
  Literal* add(LiteralBool* left, LiteralDouble* right);
  Literal* add(LiteralDouble* left, LiteralInt* right);
  Literal* add(LiteralDouble* left, LiteralFloat* right);
  Literal* add(LiteralDouble* left, LiteralString* right);
  Literal* add(LiteralDouble* left, LiteralBool* right);
  Literal* add(LiteralDouble* left, LiteralDouble* right);

  Literal* subtract(LiteralInt* left, LiteralInt* right);
  Literal* subtract(LiteralInt* left, LiteralFloat* right);
  Literal* subtract(LiteralInt* left, LiteralString* right);
  Literal* subtract(LiteralInt* left, LiteralBool* right);
  Literal* subtract(LiteralInt* left, LiteralDouble* right);
  Literal* subtract(LiteralFloat* left, LiteralInt* right);
  Literal* subtract(LiteralFloat* left, LiteralFloat* right);
  Literal* subtract(LiteralFloat* left, LiteralString* right);
  Literal* subtract(LiteralFloat* left, LiteralBool* right);
  Literal* subtract(LiteralFloat* left, LiteralDouble* right);
  Literal* subtract(LiteralString* left, LiteralInt* right);
  Literal* subtract(LiteralString* left, LiteralFloat* right);
  Literal* subtract(LiteralString* left, LiteralString* right);
  Literal* subtract(LiteralString* left, LiteralBool* right);
  Literal* subtract(LiteralString* left, LiteralDouble* right);
  Literal* subtract(LiteralBool* left, LiteralInt* right);
  Literal* subtract(LiteralBool* left, LiteralFloat* right);
  Literal* subtract(LiteralBool* left, LiteralString* right);
  Literal* subtract(LiteralBool* left, LiteralBool* right);
  Literal* subtract(LiteralBool* left, LiteralDouble* right);
  Literal* subtract(LiteralDouble* left, LiteralInt* right);
  Literal* subtract(LiteralDouble* left, LiteralFloat* right);
  Literal* subtract(LiteralDouble* left, LiteralString* right);
  Literal* subtract(LiteralDouble* left, LiteralBool* right);
  Literal* subtract(LiteralDouble* left, LiteralDouble* right);

  Literal* multiply(LiteralInt* left, LiteralInt* right);
  Literal* multiply(LiteralInt* left, LiteralFloat* right);
  Literal* multiply(LiteralInt* left, LiteralString* right);
  Literal* multiply(LiteralInt* left, LiteralBool* right);
  Literal* multiply(LiteralInt* left, LiteralDouble* right);
  Literal* multiply(LiteralFloat* left, LiteralInt* right);
  Literal* multiply(LiteralFloat* left, LiteralFloat* right);
  Literal* multiply(LiteralFloat* left, LiteralString* right);
  Literal* multiply(LiteralFloat* left, LiteralBool* right);
  Literal* multiply(LiteralFloat* left, LiteralDouble* right);
  Literal* multiply(LiteralString* left, LiteralInt* right);
  Literal* multiply(LiteralString* left, LiteralFloat* right);
  Literal* multiply(LiteralString* left, LiteralString* right);
  Literal* multiply(LiteralString* left, LiteralBool* right);
  Literal* multiply(LiteralString* left, LiteralDouble* right);
  Literal* multiply(LiteralBool* left, LiteralInt* right);
  Literal* multiply(LiteralBool* left, LiteralFloat* right);
  Literal* multiply(LiteralBool* left, LiteralString* right);
  Literal* multiply(LiteralBool* left, LiteralBool* right);
  Literal* multiply(LiteralBool* left, LiteralDouble* right);
  Literal* multiply(LiteralDouble* left, LiteralInt* right);
  Literal* multiply(LiteralDouble* left, LiteralFloat* right);
  Literal* multiply(LiteralDouble* left, LiteralString* right);
  Literal* multiply(LiteralDouble* left, LiteralBool* right);
  Literal* multiply(LiteralDouble* left, LiteralDouble* right);

  Literal* divide(LiteralInt* left, LiteralInt* right);
  Literal* divide(LiteralInt* left, LiteralFloat* right);
  Literal* divide(LiteralInt* left, LiteralString* right);
  Literal* divide(LiteralInt* left, LiteralBool* right);
  Literal* divide(LiteralInt* left, LiteralDouble* right);
  Literal* divide(LiteralFloat* left, LiteralInt* right);
  Literal* divide(LiteralFloat* left, LiteralFloat* right);
  Literal* divide(LiteralFloat* left, LiteralString* right);
  Literal* divide(LiteralFloat* left, LiteralBool* right);
  Literal* divide(LiteralFloat* left, LiteralDouble* right);
  Literal* divide(LiteralString* left, LiteralInt* right);
  Literal* divide(LiteralString* left, LiteralFloat* right);
  Literal* divide(LiteralString* left, LiteralString* right);
  Literal* divide(LiteralString* left, LiteralBool* right);
  Literal* divide(LiteralString* left, LiteralDouble* right);
  Literal* divide(LiteralBool* left, LiteralInt* right);
  Literal* divide(LiteralBool* left, LiteralFloat* right);
  Literal* divide(LiteralBool* left, LiteralString* right);
  Literal* divide(LiteralBool* left, LiteralBool* right);
  Literal* divide(LiteralBool* left, LiteralDouble* right);
  Literal* divide(LiteralDouble* left, LiteralInt* right);
  Literal* divide(LiteralDouble* left, LiteralFloat* right);
  Literal* divide(LiteralDouble* left, LiteralString* right);
  Literal* divide(LiteralDouble* left, LiteralBool* right);
  Literal* divide(LiteralDouble* left, LiteralDouble* right);

  Literal* modulo(LiteralInt* left, LiteralInt* right);
  Literal* modulo(LiteralInt* left, LiteralFloat* right);
  Literal* modulo(LiteralInt* left, LiteralString* right);
  Literal* modulo(LiteralInt* left, LiteralBool* right);
  Literal* modulo(LiteralInt* left, LiteralDouble* right);
  Literal* modulo(LiteralFloat* left, LiteralInt* right);
  Literal* modulo(LiteralFloat* left, LiteralFloat* right);
  Literal* modulo(LiteralFloat* left, LiteralString* right);
  Literal* modulo(LiteralFloat* left, LiteralBool* right);
  Literal* modulo(LiteralFloat* left, LiteralDouble* right);
  Literal* modulo(LiteralString* left, LiteralInt* right);
  Literal* modulo(LiteralString* left, LiteralFloat* right);
  Literal* modulo(LiteralString* left, LiteralString* right);
  Literal* modulo(LiteralString* left, LiteralBool* right);
  Literal* modulo(LiteralString* left, LiteralDouble* right);
  Literal* modulo(LiteralBool* left, LiteralInt* right);
  Literal* modulo(LiteralBool* left, LiteralFloat* right);
  Literal* modulo(LiteralBool* left, LiteralString* right);
  Literal* modulo(LiteralBool* left, LiteralBool* right);
  Literal* modulo(LiteralBool* left, LiteralDouble* right);
  Literal* modulo(LiteralDouble* left, LiteralInt* right);
  Literal* modulo(LiteralDouble* left, LiteralFloat* right);
  Literal* modulo(LiteralDouble* left, LiteralString* right);
  Literal* modulo(LiteralDouble* left, LiteralBool* right);
  Literal* modulo(LiteralDouble* left, LiteralDouble* right);
};

#endif  // OPERATIONS_DISPATCHER_H