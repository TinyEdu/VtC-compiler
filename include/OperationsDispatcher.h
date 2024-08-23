// OperationsDispatcher.h

#ifndef OPERATIONS_DISPATCHER_H
#define OPERATIONS_DISPATCHER_H

#include "Token.h"

// forward declarations
class LiteralInt;
class LiteralFloat;
class LiteralString;
class LiteralBool;
class LiteralDouble;
class Literal;
class Expression;

class OperationsDispatcher {
 public:
  template <typename T1, typename T2>
  static Expression* dispatch(T1* left, T2* right, Token token) {
    switch (token.type) {
      case TokenType::PLUS:
        return add(left, right);
        break;
      case TokenType::MINUS:
        return subtract(left, right);
        break;
      case TokenType::STAR:
        return multiply(left, right);
        break;
      case TokenType::SLASH:  
        return divide(left, right);
        break;
      case TokenType::MODULO:
        return modulo(left, right);
        break;
      
      default:
        break;
    }

    return nullptr;
  }

  template <typename T1>
  static Expression* dispatch(T1* lt, Token token) {
    switch (token.type) {
      case TokenType::MINUS:
        return negate(lt);
        break;
     case TokenType::BANG:
        return negate(lt);
        break;
      
      default:
        break;
    }

    return nullptr;
  }


  // Every unique possible combination of dispatches for literals
  static Literal* add(LiteralInt* left, LiteralInt* right);
static Literal* add(LiteralInt* left, LiteralFloat* right);
static Literal* add(LiteralInt* left, LiteralString* right);
static Literal* add(LiteralInt* left, LiteralBool* right);
static Literal* add(LiteralInt* left, LiteralDouble* right);
static Literal* add(LiteralFloat* left, LiteralInt* right);
static Literal* add(LiteralFloat* left, LiteralFloat* right);
static Literal* add(LiteralFloat* left, LiteralString* right);
static Literal* add(LiteralFloat* left, LiteralBool* right);
static Literal* add(LiteralFloat* left, LiteralDouble* right);
static Literal* add(LiteralString* left, LiteralInt* right);
static Literal* add(LiteralString* left, LiteralFloat* right);
static Literal* add(LiteralString* left, LiteralString* right);
static Literal* add(LiteralString* left, LiteralBool* right);
static Literal* add(LiteralString* left, LiteralDouble* right);
static Literal* add(LiteralBool* left, LiteralInt* right);
static Literal* add(LiteralBool* left, LiteralFloat* right);
static Literal* add(LiteralBool* left, LiteralString* right);
static Literal* add(LiteralBool* left, LiteralBool* right);
static Literal* add(LiteralBool* left, LiteralDouble* right);
static Literal* add(LiteralDouble* left, LiteralInt* right);
static Literal* add(LiteralDouble* left, LiteralFloat* right);
static Literal* add(LiteralDouble* left, LiteralString* right);
static Literal* add(LiteralDouble* left, LiteralBool* right);
static Literal* add(LiteralDouble* left, LiteralDouble* right);

static Literal* subtract(LiteralInt* left, LiteralInt* right);
static Literal* subtract(LiteralInt* left, LiteralFloat* right);
static Literal* subtract(LiteralInt* left, LiteralString* right);
static Literal* subtract(LiteralInt* left, LiteralBool* right);
static Literal* subtract(LiteralInt* left, LiteralDouble* right);
static Literal* subtract(LiteralFloat* left, LiteralInt* right);
static Literal* subtract(LiteralFloat* left, LiteralFloat* right);
static Literal* subtract(LiteralFloat* left, LiteralString* right);
static Literal* subtract(LiteralFloat* left, LiteralBool* right);
static Literal* subtract(LiteralFloat* left, LiteralDouble* right);
static Literal* subtract(LiteralString* left, LiteralInt* right);
static Literal* subtract(LiteralString* left, LiteralFloat* right);
static Literal* subtract(LiteralString* left, LiteralString* right);
static Literal* subtract(LiteralString* left, LiteralBool* right);
static Literal* subtract(LiteralString* left, LiteralDouble* right);
static Literal* subtract(LiteralBool* left, LiteralInt* right);
static Literal* subtract(LiteralBool* left, LiteralFloat* right);
static Literal* subtract(LiteralBool* left, LiteralString* right);
static Literal* subtract(LiteralBool* left, LiteralBool* right);
static Literal* subtract(LiteralBool* left, LiteralDouble* right);
static Literal* subtract(LiteralDouble* left, LiteralInt* right);
static Literal* subtract(LiteralDouble* left, LiteralFloat* right);
static Literal* subtract(LiteralDouble* left, LiteralString* right);
static Literal* subtract(LiteralDouble* left, LiteralBool* right);
static Literal* subtract(LiteralDouble* left, LiteralDouble* right);

static Literal* multiply(LiteralInt* left, LiteralInt* right);
static Literal* multiply(LiteralInt* left, LiteralFloat* right);
static Literal* multiply(LiteralInt* left, LiteralString* right);
static Literal* multiply(LiteralInt* left, LiteralBool* right);
static Literal* multiply(LiteralInt* left, LiteralDouble* right);
static Literal* multiply(LiteralFloat* left, LiteralInt* right);
static Literal* multiply(LiteralFloat* left, LiteralFloat* right);
static Literal* multiply(LiteralFloat* left, LiteralString* right);
static Literal* multiply(LiteralFloat* left, LiteralBool* right);
static Literal* multiply(LiteralFloat* left, LiteralDouble* right);
static Literal* multiply(LiteralString* left, LiteralInt* right);
static Literal* multiply(LiteralString* left, LiteralFloat* right);
static Literal* multiply(LiteralString* left, LiteralString* right);
static Literal* multiply(LiteralString* left, LiteralBool* right);
static Literal* multiply(LiteralString* left, LiteralDouble* right);
static Literal* multiply(LiteralBool* left, LiteralInt* right);
static Literal* multiply(LiteralBool* left, LiteralFloat* right);
static Literal* multiply(LiteralBool* left, LiteralString* right);
static Literal* multiply(LiteralBool* left, LiteralBool* right);
static Literal* multiply(LiteralBool* left, LiteralDouble* right);
static Literal* multiply(LiteralDouble* left, LiteralInt* right);
static Literal* multiply(LiteralDouble* left, LiteralFloat* right);
static Literal* multiply(LiteralDouble* left, LiteralString* right);
static Literal* multiply(LiteralDouble* left, LiteralBool* right);
static Literal* multiply(LiteralDouble* left, LiteralDouble* right);

static Literal* divide(LiteralInt* left, LiteralInt* right);
static Literal* divide(LiteralInt* left, LiteralFloat* right);
static Literal* divide(LiteralInt* left, LiteralString* right);
static Literal* divide(LiteralInt* left, LiteralBool* right);
static Literal* divide(LiteralInt* left, LiteralDouble* right);
static Literal* divide(LiteralFloat* left, LiteralInt* right);
static Literal* divide(LiteralFloat* left, LiteralFloat* right);
static Literal* divide(LiteralFloat* left, LiteralString* right);
static Literal* divide(LiteralFloat* left, LiteralBool* right);
static Literal* divide(LiteralFloat* left, LiteralDouble* right);
static Literal* divide(LiteralString* left, LiteralInt* right);
static Literal* divide(LiteralString* left, LiteralFloat* right);
static Literal* divide(LiteralString* left, LiteralString* right);
static Literal* divide(LiteralString* left, LiteralBool* right);
static Literal* divide(LiteralString* left, LiteralDouble* right);
static Literal* divide(LiteralBool* left, LiteralInt* right);
static Literal* divide(LiteralBool* left, LiteralFloat* right);
static Literal* divide(LiteralBool* left, LiteralString* right);
static Literal* divide(LiteralBool* left, LiteralBool* right);
static Literal* divide(LiteralBool* left, LiteralDouble* right);
static Literal* divide(LiteralDouble* left, LiteralInt* right);
static Literal* divide(LiteralDouble* left, LiteralFloat* right);
static Literal* divide(LiteralDouble* left, LiteralString* right);
static Literal* divide(LiteralDouble* left, LiteralBool* right);
static Literal* divide(LiteralDouble* left, LiteralDouble* right);

static Literal* modulo(LiteralInt* left, LiteralInt* right);
static Literal* modulo(LiteralInt* left, LiteralFloat* right);
static Literal* modulo(LiteralInt* left, LiteralString* right);
static Literal* modulo(LiteralInt* left, LiteralBool* right);
static Literal* modulo(LiteralInt* left, LiteralDouble* right);
static Literal* modulo(LiteralFloat* left, LiteralInt* right);
static Literal* modulo(LiteralFloat* left, LiteralFloat* right);
static Literal* modulo(LiteralFloat* left, LiteralString* right);
static Literal* modulo(LiteralFloat* left, LiteralBool* right);
static Literal* modulo(LiteralFloat* left, LiteralDouble* right);
static Literal* modulo(LiteralString* left, LiteralInt* right);
static Literal* modulo(LiteralString* left, LiteralFloat* right);
static Literal* modulo(LiteralString* left, LiteralString* right);
static Literal* modulo(LiteralString* left, LiteralBool* right);
static Literal* modulo(LiteralString* left, LiteralDouble* right);
static Literal* modulo(LiteralBool* left, LiteralInt* right);
static Literal* modulo(LiteralBool* left, LiteralFloat* right);
static Literal* modulo(LiteralBool* left, LiteralString* right);
static Literal* modulo(LiteralBool* left, LiteralBool* right);
static Literal* modulo(LiteralBool* left, LiteralDouble* right);
static Literal* modulo(LiteralDouble* left, LiteralInt* right);
static Literal* modulo(LiteralDouble* left, LiteralFloat* right);
static Literal* modulo(LiteralDouble* left, LiteralString* right);
static Literal* modulo(LiteralDouble* left, LiteralBool* right);
static Literal* modulo(LiteralDouble* left, LiteralDouble* right);

static Literal* negate(LiteralInt* right);
static Literal* negate(LiteralFloat* right);
static Literal* negate(LiteralString* right);
static Literal* negate(LiteralBool* right);
static Literal* negate(LiteralDouble* right);
};

#endif  // OPERATIONS_DISPATCHER_H