// MultiplyingExpressions.cpp
#include <gtest/gtest.h>
#include "Expression.h"
#include "Interpreter.h"

// Test multiplying positive numbers
TEST(InterpreterTest, MultipliesPositiveNumbers) {
    Interpreter interpreter;
    Binary* expr1 = new Binary(new Literal(2), Token(TokenType::STAR), new Literal(3));
    Binary* expr2 = new Binary(new Literal(10), Token(TokenType::STAR), new Literal(20));
    Binary* expr3 = new Binary(new Literal(5), Token(TokenType::STAR), new Literal(5));
    
    EXPECT_EQ(interpreter.evaluate(expr1), Literal(6));
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(200));
    EXPECT_EQ(interpreter.evaluate(expr3), Literal(25));
}

// Test multiplying negative numbers
TEST(InterpreterTest, MultipliesNegativeNumbers) {
    Interpreter interpreter;
    Binary* expr1 = new Binary(new Literal(-2), Token(TokenType::STAR), new Literal(-3));
    Binary* expr2 = new Binary(new Literal(-5), Token(TokenType::STAR), new Literal(-5));
    Binary* expr3 = new Binary(new Literal(-10), Token(TokenType::STAR), new Literal(-20));
    
    EXPECT_EQ(interpreter.evaluate(expr1), Literal(6));
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(25));
    EXPECT_EQ(interpreter.evaluate(expr3), Literal(200));
}

// Test multiplying positive and negative numbers
TEST(InterpreterTest, MultipliesPositiveAndNegativeNumbers) {
    Interpreter interpreter;
    Binary* expr1 = new Binary(new Literal(3), Token(TokenType::STAR), new Literal(-4));
    Binary* expr2 = new Binary(new Literal(-7), Token(TokenType::STAR), new Literal(6));
    Binary* expr3 = new Binary(new Literal(5), Token(TokenType::STAR), new Literal(-5));
    
    EXPECT_EQ(interpreter.evaluate(expr1), Literal(-12));
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(-42));
    EXPECT_EQ(interpreter.evaluate(expr3), Literal(-25));

    Binary* expr4 = new Binary(new Literal(-1), Token(TokenType::STAR), new Literal(10));
    Binary* expr5 = new Binary(new Literal(0), Token(TokenType::STAR), new Literal(1234));
    Binary* expr6 = new Binary(new Literal(1234), Token(TokenType::STAR), new Literal(0));
    
    EXPECT_EQ(interpreter.evaluate(expr4), Literal(-10));
    EXPECT_EQ(interpreter.evaluate(expr5), Literal(0));
    EXPECT_EQ(interpreter.evaluate(expr6), Literal(0));
}

// Test multiplying with zero
TEST(InterpreterTest, MultipliesWithZero) {
    Interpreter interpreter;
    Binary* expr1 = new Binary(new Literal(0), Token(TokenType::STAR), new Literal(100));
    Binary* expr2 = new Binary(new Literal(100), Token(TokenType::STAR), new Literal(0));
    Binary* expr3 = new Binary(new Literal(0), Token(TokenType::STAR), new Literal(0));
    
    EXPECT_EQ(interpreter.evaluate(expr1), Literal(0));
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(0));
    EXPECT_EQ(interpreter.evaluate(expr3), Literal(0));
}
