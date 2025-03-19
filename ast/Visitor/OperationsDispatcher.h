// OperationsDispatcher.h

#ifndef OPERATIONS_DISPATCHER_H
#define OPERATIONS_DISPATCHER_H

#include <memory>

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
    static std::shared_ptr<Expression> dispatch(std::shared_ptr<T1> left, std::shared_ptr<T2> right, Token token)
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
            LOG() << "Unreachable code reached in OperationsDispatcher::dispatch(T1, "
                "T2, Token)";
            return nullptr;
        }
    }

    template <typename T1>
    static std::shared_ptr<Expression> dispatch(std::shared_ptr<T1> lt, Token token)
    {
        switch (token.type)
        {
        case TokenType::MINUS:
        case TokenType::BANG:
            return negate(lt);
        default:
            LOG() << "Unreachable code reached in OperationsDispatcher::dispatch(T1, Token)";
        }

        return nullptr;
    }


    // add functions
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> add(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralBool> right);


    // subtract functions
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> subtract(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralBool> right);


    // multiply functions
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> multiply(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralBool> right);


    // divide functions
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> divide(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralBool> right);


    // equal functions
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> equal(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralBool> right);


    // not_equal functions
    static std::shared_ptr<Literal> not_equal(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> not_equal(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> not_equal(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> not_equal(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> not_equal(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> not_equal(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> not_equal(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> not_equal(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> not_equal(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> not_equal(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> not_equal(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> not_equal(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal>
    not_equal(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal>
    not_equal(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> not_equal(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> not_equal(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> not_equal(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal>
    not_equal(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal>
    not_equal(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> not_equal(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> not_equal(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> not_equal(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> not_equal(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> not_equal(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> not_equal(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralBool> right);


    // greater_than functions
    static std::shared_ptr<Literal> greater_than(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> greater_than(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal>
    greater_than(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal>
    greater_than(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> greater_than(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> greater_than(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> greater_than(std::shared_ptr<LiteralFloat> left,
                                                 std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> greater_than(std::shared_ptr<LiteralFloat> left,
                                                 std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> greater_than(std::shared_ptr<LiteralFloat> left,
                                                 std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal>
    greater_than(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal>
    greater_than(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> greater_than(std::shared_ptr<LiteralDouble> left,
                                                 std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> greater_than(std::shared_ptr<LiteralDouble> left,
                                                 std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> greater_than(std::shared_ptr<LiteralDouble> left,
                                                 std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> greater_than(std::shared_ptr<LiteralDouble> left,
                                                 std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal>
    greater_than(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> greater_than(std::shared_ptr<LiteralString> left,
                                                 std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> greater_than(std::shared_ptr<LiteralString> left,
                                                 std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> greater_than(std::shared_ptr<LiteralString> left,
                                                 std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> greater_than(std::shared_ptr<LiteralString> left,
                                                 std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> greater_than(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal>
    greater_than(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> greater_than(std::shared_ptr<LiteralBool> left,
                                                 std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> greater_than(std::shared_ptr<LiteralBool> left,
                                                 std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> greater_than(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralBool> right);


    // less_than functions
    static std::shared_ptr<Literal> less_than(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> less_than(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> less_than(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> less_than(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> less_than(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> less_than(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> less_than(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> less_than(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> less_than(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> less_than(std::shared_ptr<LiteralFloat> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> less_than(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> less_than(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal>
    less_than(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal>
    less_than(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> less_than(std::shared_ptr<LiteralDouble> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> less_than(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> less_than(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal>
    less_than(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal>
    less_than(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> less_than(std::shared_ptr<LiteralString> left, std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> less_than(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> less_than(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> less_than(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> less_than(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> less_than(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralBool> right);


    // greater_than_or_equal functions
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralInt> left,
                                                          std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralInt> left,
                                                          std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralInt> left,
                                                          std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralInt> left,
                                                          std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralInt> left,
                                                          std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralFloat> left,
                                                          std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralFloat> left,
                                                          std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralFloat> left,
                                                          std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralFloat> left,
                                                          std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralFloat> left,
                                                          std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralDouble> left,
                                                          std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralDouble> left,
                                                          std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralDouble> left,
                                                          std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralDouble> left,
                                                          std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralDouble> left,
                                                          std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralString> left,
                                                          std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralString> left,
                                                          std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralString> left,
                                                          std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralString> left,
                                                          std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralString> left,
                                                          std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralBool> left,
                                                          std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralBool> left,
                                                          std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralBool> left,
                                                          std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralBool> left,
                                                          std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> greater_than_or_equal(std::shared_ptr<LiteralBool> left,
                                                          std::shared_ptr<LiteralBool> right);


    // less_than_or_equal functions
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralInt> left,
                                                       std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralInt> left,
                                                       std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralInt> left,
                                                       std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralInt> left,
                                                       std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralInt> left,
                                                       std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralFloat> left,
                                                       std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralFloat> left,
                                                       std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralFloat> left,
                                                       std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralFloat> left,
                                                       std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralFloat> left,
                                                       std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralDouble> left,
                                                       std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralDouble> left,
                                                       std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralDouble> left,
                                                       std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralDouble> left,
                                                       std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralDouble> left,
                                                       std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralString> left,
                                                       std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralString> left,
                                                       std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralString> left,
                                                       std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralString> left,
                                                       std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralString> left,
                                                       std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralBool> left,
                                                       std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralBool> left,
                                                       std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralBool> left,
                                                       std::shared_ptr<LiteralDouble> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralBool> left,
                                                       std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> less_than_or_equal(std::shared_ptr<LiteralBool> left,
                                                       std::shared_ptr<LiteralBool> right);

    // Function: negate
    static std::shared_ptr<Literal> negate(std::shared_ptr<LiteralInt> right);
    static std::shared_ptr<Literal> negate(std::shared_ptr<LiteralFloat> right);
    static std::shared_ptr<Literal> negate(std::shared_ptr<LiteralString> right);
    static std::shared_ptr<Literal> negate(std::shared_ptr<LiteralBool> right);
    static std::shared_ptr<Literal> negate(std::shared_ptr<LiteralDouble> right);
};

#endif  // OPERATIONS_DISPATCHER_H
