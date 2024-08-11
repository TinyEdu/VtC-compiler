// DivisionExpressions.cpp
#include <gtest/gtest.h>
#include "Expression.h"
#include "Interpreter.h"

// Test dividing positive numbers
TEST(InterpreterTest, NegatePositiveNumber) {
    Interpreter interpreter;

    Expression* expr1 = new Unary(Token(TokenType::MINUS), new Literal(100));
    Expression* expr2 = new Unary(Token(TokenType::MINUS), new Literal(0));
    Expression* expr3 = new Unary(Token(TokenType::MINUS), new Literal(2));

    EXPECT_EQ(interpreter.evaluate(expr1), Literal(-100));
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(0));
    EXPECT_EQ(interpreter.evaluate(expr3), Literal(-2));
}

// Test dividing negative by positive numbers
TEST(InterpreterTest, NegateNegativeNumber) {
    Interpreter interpreter;

    Expression* expr1 = new Unary(Token(TokenType::MINUS), new Literal(-100));
    Expression* expr2 = new Unary(Token(TokenType::MINUS), new Literal(-0));
    Expression* expr3 = new Unary(Token(TokenType::MINUS), new Literal(-2));

    EXPECT_EQ(interpreter.evaluate(expr1), Literal(100));
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(0));
    EXPECT_EQ(interpreter.evaluate(expr3), Literal(2));
}
