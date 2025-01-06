// OperationsDispatcher.h

#ifndef OPERATIONS_DISPATCHER_H
#define OPERATIONS_DISPATCHER_H

#include "LogManager/LogManager.h"
#include "Token/Token.h"

// forward declarations
class LiteralInt;
class LiteralFloat;
class LiteralString;
class LiteralBool;
class LiteralDouble;
class Literal;
class Expression;

class OperationsDispatcher
{
public:
    template <typename T1, typename T2>
    static Expression* dispatch(T1* left, T2* right, Token token)
    {
        switch (token.type)
        {
        case TokenType::PLUS:
            return add(left, right);
        case TokenType::MINUS:
            return subtract(left, right);
        case TokenType::STAR:
            return multiply(left, right);
        case TokenType::SLASH:
            return divide(left, right);
        case TokenType::EQUAL_EQUAL:
            return equal(left, right);
        case TokenType::BANG_EQUAL:
            return not_equal(left, right);
        case TokenType::GREATER:
            return greater_than(left, right);
        case TokenType::GREATER_EQUAL:
            return greater_than_or_equal(left, right);
        case TokenType::LESS:
            return less_than(left, right);
        case TokenType::LESS_EQUAL:
            return less_than_or_equal(left, right);

        default:
            break;
        }
        LogManager::log() << "Unreachable code reached in OperationsDispatcher::dispatch(T1*, "
            "T2*, Token)";
        return nullptr;
    }

    template <typename T1>
    static Expression* dispatch(T1* lt, Token token)
    {
        switch (token.type)
        {
        case TokenType::MINUS:
            return negate(lt);
            break;
        case TokenType::BANG:
            return negate(lt);
            break;

        default:
            break;
        }

        LogManager::log() << "Unreachable code reached in OperationsDispatcher::dispatch(T1*, "
            "Token)";
        return nullptr;
    }

    // Function: add
    static Literal* add(LiteralInt* left, LiteralBool* right);
    static Literal* add(LiteralDouble* left, LiteralBool* right);
    static Literal* add(LiteralFloat* left, LiteralBool* right);
    static Literal* add(LiteralString* left, LiteralBool* right);
    static Literal* add(LiteralBool* left, LiteralBool* right);
    static Literal* add(LiteralInt* left, LiteralString* right);
    static Literal* add(LiteralDouble* left, LiteralString* right);
    static Literal* add(LiteralFloat* left, LiteralString* right);
    static Literal* add(LiteralString* left, LiteralString* right);
    static Literal* add(LiteralBool* left, LiteralString* right);
    static Literal* add(LiteralInt* left, LiteralFloat* right);
    static Literal* add(LiteralDouble* left, LiteralFloat* right);
    static Literal* add(LiteralFloat* left, LiteralFloat* right);
    static Literal* add(LiteralString* left, LiteralFloat* right);
    static Literal* add(LiteralBool* left, LiteralFloat* right);
    static Literal* add(LiteralInt* left, LiteralDouble* right);
    static Literal* add(LiteralDouble* left, LiteralDouble* right);
    static Literal* add(LiteralFloat* left, LiteralDouble* right);
    static Literal* add(LiteralString* left, LiteralDouble* right);
    static Literal* add(LiteralBool* left, LiteralDouble* right);
    static Literal* add(LiteralInt* left, LiteralInt* right);
    static Literal* add(LiteralDouble* left, LiteralInt* right);
    static Literal* add(LiteralFloat* left, LiteralInt* right);
    static Literal* add(LiteralString* left, LiteralInt* right);
    static Literal* add(LiteralBool* left, LiteralInt* right);

    // Function: subtract
    static Literal* subtract(LiteralInt* left, LiteralBool* right);
    static Literal* subtract(LiteralDouble* left, LiteralBool* right);
    static Literal* subtract(LiteralFloat* left, LiteralBool* right);
    static Literal* subtract(LiteralString* left, LiteralBool* right);
    static Literal* subtract(LiteralBool* left, LiteralBool* right);
    static Literal* subtract(LiteralInt* left, LiteralString* right);
    static Literal* subtract(LiteralDouble* left, LiteralString* right);
    static Literal* subtract(LiteralFloat* left, LiteralString* right);
    static Literal* subtract(LiteralString* left, LiteralString* right);
    static Literal* subtract(LiteralBool* left, LiteralString* right);
    static Literal* subtract(LiteralInt* left, LiteralFloat* right);
    static Literal* subtract(LiteralDouble* left, LiteralFloat* right);
    static Literal* subtract(LiteralFloat* left, LiteralFloat* right);
    static Literal* subtract(LiteralString* left, LiteralFloat* right);
    static Literal* subtract(LiteralBool* left, LiteralFloat* right);
    static Literal* subtract(LiteralInt* left, LiteralDouble* right);
    static Literal* subtract(LiteralDouble* left, LiteralDouble* right);
    static Literal* subtract(LiteralFloat* left, LiteralDouble* right);
    static Literal* subtract(LiteralString* left, LiteralDouble* right);
    static Literal* subtract(LiteralBool* left, LiteralDouble* right);
    static Literal* subtract(LiteralInt* left, LiteralInt* right);
    static Literal* subtract(LiteralDouble* left, LiteralInt* right);
    static Literal* subtract(LiteralFloat* left, LiteralInt* right);
    static Literal* subtract(LiteralString* left, LiteralInt* right);
    static Literal* subtract(LiteralBool* left, LiteralInt* right);

    // Function: multiply
    static Literal* multiply(LiteralInt* left, LiteralBool* right);
    static Literal* multiply(LiteralDouble* left, LiteralBool* right);
    static Literal* multiply(LiteralFloat* left, LiteralBool* right);
    static Literal* multiply(LiteralString* left, LiteralBool* right);
    static Literal* multiply(LiteralBool* left, LiteralBool* right);
    static Literal* multiply(LiteralInt* left, LiteralString* right);
    static Literal* multiply(LiteralDouble* left, LiteralString* right);
    static Literal* multiply(LiteralFloat* left, LiteralString* right);
    static Literal* multiply(LiteralString* left, LiteralString* right);
    static Literal* multiply(LiteralBool* left, LiteralString* right);
    static Literal* multiply(LiteralInt* left, LiteralFloat* right);
    static Literal* multiply(LiteralDouble* left, LiteralFloat* right);
    static Literal* multiply(LiteralFloat* left, LiteralFloat* right);
    static Literal* multiply(LiteralString* left, LiteralFloat* right);
    static Literal* multiply(LiteralBool* left, LiteralFloat* right);
    static Literal* multiply(LiteralInt* left, LiteralDouble* right);
    static Literal* multiply(LiteralDouble* left, LiteralDouble* right);
    static Literal* multiply(LiteralFloat* left, LiteralDouble* right);
    static Literal* multiply(LiteralString* left, LiteralDouble* right);
    static Literal* multiply(LiteralBool* left, LiteralDouble* right);
    static Literal* multiply(LiteralInt* left, LiteralInt* right);
    static Literal* multiply(LiteralDouble* left, LiteralInt* right);
    static Literal* multiply(LiteralFloat* left, LiteralInt* right);
    static Literal* multiply(LiteralString* left, LiteralInt* right);
    static Literal* multiply(LiteralBool* left, LiteralInt* right);

    // Function: divide
    static Literal* divide(LiteralInt* left, LiteralBool* right);
    static Literal* divide(LiteralDouble* left, LiteralBool* right);
    static Literal* divide(LiteralFloat* left, LiteralBool* right);
    static Literal* divide(LiteralString* left, LiteralBool* right);
    static Literal* divide(LiteralBool* left, LiteralBool* right);
    static Literal* divide(LiteralInt* left, LiteralString* right);
    static Literal* divide(LiteralDouble* left, LiteralString* right);
    static Literal* divide(LiteralFloat* left, LiteralString* right);
    static Literal* divide(LiteralString* left, LiteralString* right);
    static Literal* divide(LiteralBool* left, LiteralString* right);
    static Literal* divide(LiteralInt* left, LiteralFloat* right);
    static Literal* divide(LiteralDouble* left, LiteralFloat* right);
    static Literal* divide(LiteralFloat* left, LiteralFloat* right);
    static Literal* divide(LiteralString* left, LiteralFloat* right);
    static Literal* divide(LiteralBool* left, LiteralFloat* right);
    static Literal* divide(LiteralInt* left, LiteralDouble* right);
    static Literal* divide(LiteralDouble* left, LiteralDouble* right);
    static Literal* divide(LiteralFloat* left, LiteralDouble* right);
    static Literal* divide(LiteralString* left, LiteralDouble* right);
    static Literal* divide(LiteralBool* left, LiteralDouble* right);
    static Literal* divide(LiteralInt* left, LiteralInt* right);
    static Literal* divide(LiteralDouble* left, LiteralInt* right);
    static Literal* divide(LiteralFloat* left, LiteralInt* right);
    static Literal* divide(LiteralString* left, LiteralInt* right);
    static Literal* divide(LiteralBool* left, LiteralInt* right);

    // Function: equal
    static Literal* equal(LiteralInt* left, LiteralBool* right);
    static Literal* equal(LiteralDouble* left, LiteralBool* right);
    static Literal* equal(LiteralFloat* left, LiteralBool* right);
    static Literal* equal(LiteralString* left, LiteralBool* right);
    static Literal* equal(LiteralBool* left, LiteralBool* right);
    static Literal* equal(LiteralInt* left, LiteralString* right);
    static Literal* equal(LiteralDouble* left, LiteralString* right);
    static Literal* equal(LiteralFloat* left, LiteralString* right);
    static Literal* equal(LiteralString* left, LiteralString* right);
    static Literal* equal(LiteralBool* left, LiteralString* right);
    static Literal* equal(LiteralInt* left, LiteralFloat* right);
    static Literal* equal(LiteralDouble* left, LiteralFloat* right);
    static Literal* equal(LiteralFloat* left, LiteralFloat* right);
    static Literal* equal(LiteralString* left, LiteralFloat* right);
    static Literal* equal(LiteralBool* left, LiteralFloat* right);
    static Literal* equal(LiteralInt* left, LiteralDouble* right);
    static Literal* equal(LiteralDouble* left, LiteralDouble* right);
    static Literal* equal(LiteralFloat* left, LiteralDouble* right);
    static Literal* equal(LiteralString* left, LiteralDouble* right);
    static Literal* equal(LiteralBool* left, LiteralDouble* right);
    static Literal* equal(LiteralInt* left, LiteralInt* right);
    static Literal* equal(LiteralDouble* left, LiteralInt* right);
    static Literal* equal(LiteralFloat* left, LiteralInt* right);
    static Literal* equal(LiteralString* left, LiteralInt* right);
    static Literal* equal(LiteralBool* left, LiteralInt* right);

    // Function: not_equal
    static Literal* not_equal(LiteralInt* left, LiteralBool* right);
    static Literal* not_equal(LiteralDouble* left, LiteralBool* right);
    static Literal* not_equal(LiteralFloat* left, LiteralBool* right);
    static Literal* not_equal(LiteralString* left, LiteralBool* right);
    static Literal* not_equal(LiteralBool* left, LiteralBool* right);
    static Literal* not_equal(LiteralInt* left, LiteralString* right);
    static Literal* not_equal(LiteralDouble* left, LiteralString* right);
    static Literal* not_equal(LiteralFloat* left, LiteralString* right);
    static Literal* not_equal(LiteralString* left, LiteralString* right);
    static Literal* not_equal(LiteralBool* left, LiteralString* right);
    static Literal* not_equal(LiteralInt* left, LiteralFloat* right);
    static Literal* not_equal(LiteralDouble* left, LiteralFloat* right);
    static Literal* not_equal(LiteralFloat* left, LiteralFloat* right);
    static Literal* not_equal(LiteralString* left, LiteralFloat* right);
    static Literal* not_equal(LiteralBool* left, LiteralFloat* right);
    static Literal* not_equal(LiteralInt* left, LiteralDouble* right);
    static Literal* not_equal(LiteralDouble* left, LiteralDouble* right);
    static Literal* not_equal(LiteralFloat* left, LiteralDouble* right);
    static Literal* not_equal(LiteralString* left, LiteralDouble* right);
    static Literal* not_equal(LiteralBool* left, LiteralDouble* right);
    static Literal* not_equal(LiteralInt* left, LiteralInt* right);
    static Literal* not_equal(LiteralDouble* left, LiteralInt* right);
    static Literal* not_equal(LiteralFloat* left, LiteralInt* right);
    static Literal* not_equal(LiteralString* left, LiteralInt* right);
    static Literal* not_equal(LiteralBool* left, LiteralInt* right);

    // Function: greater_than
    static Literal* greater_than(LiteralInt* left, LiteralBool* right);
    static Literal* greater_than(LiteralDouble* left, LiteralBool* right);
    static Literal* greater_than(LiteralFloat* left, LiteralBool* right);
    static Literal* greater_than(LiteralString* left, LiteralBool* right);
    static Literal* greater_than(LiteralBool* left, LiteralBool* right);
    static Literal* greater_than(LiteralInt* left, LiteralString* right);
    static Literal* greater_than(LiteralDouble* left, LiteralString* right);
    static Literal* greater_than(LiteralFloat* left, LiteralString* right);
    static Literal* greater_than(LiteralString* left, LiteralString* right);
    static Literal* greater_than(LiteralBool* left, LiteralString* right);
    static Literal* greater_than(LiteralInt* left, LiteralFloat* right);
    static Literal* greater_than(LiteralDouble* left, LiteralFloat* right);
    static Literal* greater_than(LiteralFloat* left, LiteralFloat* right);
    static Literal* greater_than(LiteralString* left, LiteralFloat* right);
    static Literal* greater_than(LiteralBool* left, LiteralFloat* right);
    static Literal* greater_than(LiteralInt* left, LiteralDouble* right);
    static Literal* greater_than(LiteralDouble* left, LiteralDouble* right);
    static Literal* greater_than(LiteralFloat* left, LiteralDouble* right);
    static Literal* greater_than(LiteralString* left, LiteralDouble* right);
    static Literal* greater_than(LiteralBool* left, LiteralDouble* right);
    static Literal* greater_than(LiteralInt* left, LiteralInt* right);
    static Literal* greater_than(LiteralDouble* left, LiteralInt* right);
    static Literal* greater_than(LiteralFloat* left, LiteralInt* right);
    static Literal* greater_than(LiteralString* left, LiteralInt* right);
    static Literal* greater_than(LiteralBool* left, LiteralInt* right);

    // Function: less_than
    static Literal* less_than(LiteralInt* left, LiteralBool* right);
    static Literal* less_than(LiteralDouble* left, LiteralBool* right);
    static Literal* less_than(LiteralFloat* left, LiteralBool* right);
    static Literal* less_than(LiteralString* left, LiteralBool* right);
    static Literal* less_than(LiteralBool* left, LiteralBool* right);
    static Literal* less_than(LiteralInt* left, LiteralString* right);
    static Literal* less_than(LiteralDouble* left, LiteralString* right);
    static Literal* less_than(LiteralFloat* left, LiteralString* right);
    static Literal* less_than(LiteralString* left, LiteralString* right);
    static Literal* less_than(LiteralBool* left, LiteralString* right);
    static Literal* less_than(LiteralInt* left, LiteralFloat* right);
    static Literal* less_than(LiteralDouble* left, LiteralFloat* right);
    static Literal* less_than(LiteralFloat* left, LiteralFloat* right);
    static Literal* less_than(LiteralString* left, LiteralFloat* right);
    static Literal* less_than(LiteralBool* left, LiteralFloat* right);
    static Literal* less_than(LiteralInt* left, LiteralDouble* right);
    static Literal* less_than(LiteralDouble* left, LiteralDouble* right);
    static Literal* less_than(LiteralFloat* left, LiteralDouble* right);
    static Literal* less_than(LiteralString* left, LiteralDouble* right);
    static Literal* less_than(LiteralBool* left, LiteralDouble* right);
    static Literal* less_than(LiteralInt* left, LiteralInt* right);
    static Literal* less_than(LiteralDouble* left, LiteralInt* right);
    static Literal* less_than(LiteralFloat* left, LiteralInt* right);
    static Literal* less_than(LiteralString* left, LiteralInt* right);
    static Literal* less_than(LiteralBool* left, LiteralInt* right);

    // Function: greater_than_or_equal
    static Literal* greater_than_or_equal(LiteralInt* left, LiteralBool* right);
    static Literal* greater_than_or_equal(LiteralDouble* left, LiteralBool* right);
    static Literal* greater_than_or_equal(LiteralFloat* left, LiteralBool* right);
    static Literal* greater_than_or_equal(LiteralString* left, LiteralBool* right);
    static Literal* greater_than_or_equal(LiteralBool* left, LiteralBool* right);
    static Literal* greater_than_or_equal(LiteralInt* left, LiteralString* right);
    static Literal* greater_than_or_equal(LiteralDouble* left, LiteralString* right);
    static Literal* greater_than_or_equal(LiteralFloat* left, LiteralString* right);
    static Literal* greater_than_or_equal(LiteralString* left, LiteralString* right);
    static Literal* greater_than_or_equal(LiteralBool* left, LiteralString* right);
    static Literal* greater_than_or_equal(LiteralInt* left, LiteralFloat* right);
    static Literal* greater_than_or_equal(LiteralDouble* left, LiteralFloat* right);
    static Literal* greater_than_or_equal(LiteralFloat* left, LiteralFloat* right);
    static Literal* greater_than_or_equal(LiteralString* left, LiteralFloat* right);
    static Literal* greater_than_or_equal(LiteralBool* left, LiteralFloat* right);
    static Literal* greater_than_or_equal(LiteralInt* left, LiteralDouble* right);
    static Literal* greater_than_or_equal(LiteralDouble* left, LiteralDouble* right);
    static Literal* greater_than_or_equal(LiteralFloat* left, LiteralDouble* right);
    static Literal* greater_than_or_equal(LiteralString* left, LiteralDouble* right);
    static Literal* greater_than_or_equal(LiteralBool* left, LiteralDouble* right);
    static Literal* greater_than_or_equal(LiteralInt* left, LiteralInt* right);
    static Literal* greater_than_or_equal(LiteralDouble* left, LiteralInt* right);
    static Literal* greater_than_or_equal(LiteralFloat* left, LiteralInt* right);
    static Literal* greater_than_or_equal(LiteralString* left, LiteralInt* right);
    static Literal* greater_than_or_equal(LiteralBool* left, LiteralInt* right);

    // Function: less_than_or_equal
    static Literal* less_than_or_equal(LiteralInt* left, LiteralBool* right);
    static Literal* less_than_or_equal(LiteralDouble* left, LiteralBool* right);
    static Literal* less_than_or_equal(LiteralFloat* left, LiteralBool* right);
    static Literal* less_than_or_equal(LiteralString* left, LiteralBool* right);
    static Literal* less_than_or_equal(LiteralBool* left, LiteralBool* right);
    static Literal* less_than_or_equal(LiteralInt* left, LiteralString* right);
    static Literal* less_than_or_equal(LiteralDouble* left, LiteralString* right);
    static Literal* less_than_or_equal(LiteralFloat* left, LiteralString* right);
    static Literal* less_than_or_equal(LiteralString* left, LiteralString* right);
    static Literal* less_than_or_equal(LiteralBool* left, LiteralString* right);
    static Literal* less_than_or_equal(LiteralInt* left, LiteralFloat* right);
    static Literal* less_than_or_equal(LiteralDouble* left, LiteralFloat* right);
    static Literal* less_than_or_equal(LiteralFloat* left, LiteralFloat* right);
    static Literal* less_than_or_equal(LiteralString* left, LiteralFloat* right);
    static Literal* less_than_or_equal(LiteralBool* left, LiteralFloat* right);
    static Literal* less_than_or_equal(LiteralInt* left, LiteralDouble* right);
    static Literal* less_than_or_equal(LiteralDouble* left, LiteralDouble* right);
    static Literal* less_than_or_equal(LiteralFloat* left, LiteralDouble* right);
    static Literal* less_than_or_equal(LiteralString* left, LiteralDouble* right);
    static Literal* less_than_or_equal(LiteralBool* left, LiteralDouble* right);
    static Literal* less_than_or_equal(LiteralInt* left, LiteralInt* right);
    static Literal* less_than_or_equal(LiteralDouble* left, LiteralInt* right);
    static Literal* less_than_or_equal(LiteralFloat* left, LiteralInt* right);
    static Literal* less_than_or_equal(LiteralString* left, LiteralInt* right);
    static Literal* less_than_or_equal(LiteralBool* left, LiteralInt* right);


    // Function: negate
    static Literal* negate(LiteralInt* right);
    static Literal* negate(LiteralFloat* right);
    static Literal* negate(LiteralString* right);
    static Literal* negate(LiteralBool* right);
    static Literal* negate(LiteralDouble* right);
};

#endif  // OPERATIONS_DISPATCHER_H
