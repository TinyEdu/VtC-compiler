// SubtractingExpressions.cpp
#include <gtest/gtest.h>
#include "Expression.h"
#include "Interpreter.h"

// Test subtracting positive numbers
TEST(InterpreterTest, SubtractsPositiveNumbers) {
    Interpreter interpreter;
    Binary* expr1 = new Binary(new Literal(100), Token(TokenType::MINUS), new Literal(50));
    Binary* expr2 = new Binary(new Literal(200), Token(TokenType::MINUS), new Literal(150));
    Binary* expr3 = new Binary(new Literal(500), Token(TokenType::MINUS), new Literal(300));
    
    EXPECT_EQ(interpreter.evaluate(expr1), Literal(50));
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(50));
    EXPECT_EQ(interpreter.evaluate(expr3), Literal(200));
}

// Test subtracting negative numbers
TEST(InterpreterTest, SubtractsNegativeNumbers) {
    Interpreter interpreter;
    Binary* expr1 = new Binary(new Literal(-5), Token(TokenType::MINUS), new Literal(-1));
    Binary* expr2 = new Binary(new Literal(-10), Token(TokenType::MINUS), new Literal(-5));
    Binary* expr3 = new Binary(new Literal(-20), Token(TokenType::MINUS), new Literal(-10));
    
    EXPECT_EQ(interpreter.evaluate(expr1), Literal(-4));
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(-5));
    EXPECT_EQ(interpreter.evaluate(expr3), Literal(-10));
}

// Test subtracting positive and negative numbers
TEST(InterpreterTest, SubtractsPositiveAndNegativeNumbers) {
    Interpreter interpreter;
    Binary* expr1 = new Binary(new Literal(50), Token(TokenType::MINUS), new Literal(-50));
    Binary* expr2 = new Binary(new Literal(-30), Token(TokenType::MINUS), new Literal(20));
    Binary* expr3 = new Binary(new Literal(10), Token(TokenType::MINUS), new Literal(-10));
    
    EXPECT_EQ(interpreter.evaluate(expr1), Literal(100));
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(-50));
    EXPECT_EQ(interpreter.evaluate(expr3), Literal(20));

    Binary* expr4 = new Binary(new Literal(-10), Token(TokenType::MINUS), new Literal(10));
    Binary* expr5 = new Binary(new Literal(-5), Token(TokenType::MINUS), new Literal(-15));
    Binary* expr6 = new Binary(new Literal(0), Token(TokenType::MINUS), new Literal(20));
    
    EXPECT_EQ(interpreter.evaluate(expr4), Literal(-20));
    EXPECT_EQ(interpreter.evaluate(expr5), Literal(10));
    EXPECT_EQ(interpreter.evaluate(expr6), Literal(-20));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
