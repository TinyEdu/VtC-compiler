// NegateBooleanExpressions.cpp
#include <gtest/gtest.h>
#include "Expression.h"
#include "Interpreter.h"

// Test negating boolean true
TEST(InterpreterTest, NegateBooleanTrue) {
    Interpreter interpreter;

    Expression* expr1 = new Unary(Token(TokenType::BANG), new Literal(true));

    EXPECT_EQ(interpreter.evaluate(expr1), Literal(false));
}

// Test negating boolean false
TEST(InterpreterTest, NegateBooleanFalse) {
    Interpreter interpreter;

    Expression* expr1 = new Unary(Token(TokenType::BANG), new Literal(false));

    EXPECT_EQ(interpreter.evaluate(expr1), Literal(true));
}

// Test double negation
TEST(InterpreterTest, DoubleNegation) {
    Interpreter interpreter;

    Expression* expr1 = new Unary(Token(TokenType::BANG), new Unary(Token(TokenType::BANG), new Literal(true)));
    Expression* expr2 = new Unary(Token(TokenType::BANG), new Unary(Token(TokenType::BANG), new Literal(false)));

    EXPECT_EQ(interpreter.evaluate(expr1), Literal(true));
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(false));
}

// Test negating with arithmetic results
TEST(InterpreterTest, NegateWithArithmetic) {
    Interpreter interpreter;

    // Negating a true condition (1 + 1 == 2)
    Expression* expr1 = new Unary(Token(TokenType::BANG), new Literal(1 + 1 == 2));
    // Negating a false condition (2 + 2 == 5)
    Expression* expr2 = new Unary(Token(TokenType::BANG), new Literal(2 + 2 == 5));

    EXPECT_EQ(interpreter.evaluate(expr1), Literal(false));
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(true));
}

