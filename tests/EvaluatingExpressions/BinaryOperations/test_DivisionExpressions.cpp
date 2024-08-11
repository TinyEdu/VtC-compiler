// DivisionExpressions.cpp
#include <gtest/gtest.h>
#include "Expression.h"
#include "Interpreter.h"

// Test dividing positive numbers
TEST(InterpreterTest, DividesPositiveNumbers) {
    Interpreter interpreter;
    Binary* expr1 = new Binary(new Literal(6), Token(TokenType::SLASH), new Literal(3));
    Binary* expr2 = new Binary(new Literal(100), Token(TokenType::SLASH), new Literal(10));
    Binary* expr3 = new Binary(new Literal(25), Token(TokenType::SLASH), new Literal(5));
    
    EXPECT_EQ(interpreter.evaluate(expr1), Literal(2));
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(10));
    EXPECT_EQ(interpreter.evaluate(expr3), Literal(5));
}

// Test dividing negative numbers
TEST(InterpreterTest, DividesNegativeNumbers) {
    Interpreter interpreter;
    Binary* expr1 = new Binary(new Literal(-6), Token(TokenType::SLASH), new Literal(-3));
    Binary* expr2 = new Binary(new Literal(-100), Token(TokenType::SLASH), new Literal(-10));
    Binary* expr3 = new Binary(new Literal(-25), Token(TokenType::SLASH), new Literal(-5));
    
    EXPECT_EQ(interpreter.evaluate(expr1), Literal(2));
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(10));
    EXPECT_EQ(interpreter.evaluate(expr3), Literal(5));
}

// Test dividing positive by negative numbers
TEST(InterpreterTest, DividesPositiveByNegativeNumbers) {
    Interpreter interpreter;
    Binary* expr1 = new Binary(new Literal(6), Token(TokenType::SLASH), new Literal(-3));
    Binary* expr2 = new Binary(new Literal(100), Token(TokenType::SLASH), new Literal(-10));
    Binary* expr3 = new Binary(new Literal(25), Token(TokenType::SLASH), new Literal(-5));
    
    EXPECT_EQ(interpreter.evaluate(expr1), Literal(-2));
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(-10));
    EXPECT_EQ(interpreter.evaluate(expr3), Literal(-5));
}

// Test dividing negative by positive numbers
TEST(InterpreterTest, DividesNegativeByPositiveNumbers) {
    Interpreter interpreter;
    Binary* expr1 = new Binary(new Literal(-6), Token(TokenType::SLASH), new Literal(3));
    Binary* expr2 = new Binary(new Literal(-100), Token(TokenType::SLASH), new Literal(10));
    Binary* expr3 = new Binary(new Literal(-25), Token(TokenType::SLASH), new Literal(5));
    
    EXPECT_EQ(interpreter.evaluate(expr1), Literal(-2));
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(-10));
    EXPECT_EQ(interpreter.evaluate(expr3), Literal(-5));
}

// Test division by zero
TEST(InterpreterTest, DivisionByZero) {
    Interpreter interpreter;
    Binary* expr1 = new Binary(new Literal(6), Token(TokenType::SLASH), new Literal(0));
    Binary* expr2 = new Binary(new Literal(-10), Token(TokenType::SLASH), new Literal(0));
    
    EXPECT_THROW(interpreter.evaluate(expr1), std::runtime_error);
    EXPECT_THROW(interpreter.evaluate(expr2), std::runtime_error);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
