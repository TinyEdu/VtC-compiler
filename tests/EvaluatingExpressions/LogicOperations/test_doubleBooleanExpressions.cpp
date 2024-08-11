// BooleanOperationsExpressions.cpp
#include <gtest/gtest.h>
#include "Expression.h"
#include "Interpreter.h"

// Test BANG_EQUAL (!=) operation
TEST(InterpreterTest, BangEqualOperation) {
    Interpreter interpreter;

    Expression* expr1 = new Binary(new Literal(5), Token(TokenType::BANG_EQUAL), new Literal(3));
    Expression* expr2 = new Binary(new Literal(5), Token(TokenType::BANG_EQUAL), new Literal(5));
    Expression* expr3 = new Binary(new Literal("hello"), Token(TokenType::BANG_EQUAL), new Literal("world"));
    Expression* expr4 = new Binary(new Literal(true), Token(TokenType::BANG_EQUAL), new Literal(false));

    EXPECT_EQ(interpreter.evaluate(expr1), Literal(true));  // 5 != 3
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(false)); // 5 != 5
    EXPECT_EQ(interpreter.evaluate(expr3), Literal(true));  // "hello" != "world"
    EXPECT_EQ(interpreter.evaluate(expr4), Literal(true));  // true != false
}

// Test EQUAL_EQUAL (==) operation
TEST(InterpreterTest, EqualEqualOperation) {
    Interpreter interpreter;

    Expression* expr1 = new Binary(new Literal(5), Token(TokenType::EQUAL_EQUAL), new Literal(3));
    Expression* expr2 = new Binary(new Literal(5), Token(TokenType::EQUAL_EQUAL), new Literal(5));
    Expression* expr3 = new Binary(new Literal("hello"), Token(TokenType::EQUAL_EQUAL), new Literal("hello"));
    Expression* expr4 = new Binary(new Literal(false), Token(TokenType::EQUAL_EQUAL), new Literal(false));

    EXPECT_EQ(interpreter.evaluate(expr1), Literal(false)); // 5 == 3
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(true));  // 5 == 5
    EXPECT_EQ(interpreter.evaluate(expr3), Literal(true));  // "hello" == "hello"
    EXPECT_EQ(interpreter.evaluate(expr4), Literal(true));  // false == false
}

// Test GREATER_EQUAL (>=) operation
TEST(InterpreterTest, GreaterEqualOperation) {
    Interpreter interpreter;

    Expression* expr1 = new Binary(new Literal(5), Token(TokenType::GREATER_EQUAL), new Literal(3));
    Expression* expr2 = new Binary(new Literal(5), Token(TokenType::GREATER_EQUAL), new Literal(5));
    Expression* expr3 = new Binary(new Literal(3), Token(TokenType::GREATER_EQUAL), new Literal(5));

    EXPECT_EQ(interpreter.evaluate(expr1), Literal(true));  // 5 >= 3
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(true));  // 5 >= 5
    EXPECT_EQ(interpreter.evaluate(expr3), Literal(false)); // 3 >= 5
}

// Test LESS_EQUAL (<=) operation
TEST(InterpreterTest, LessEqualOperation) {
    Interpreter interpreter;

    Expression* expr1 = new Binary(new Literal(3), Token(TokenType::LESS_EQUAL), new Literal(5));
    Expression* expr2 = new Binary(new Literal(5), Token(TokenType::LESS_EQUAL), new Literal(5));
    Expression* expr3 = new Binary(new Literal(7), Token(TokenType::LESS_EQUAL), new Literal(5));

    EXPECT_EQ(interpreter.evaluate(expr1), Literal(true));  // 3 <= 5
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(true));  // 5 <= 5
    EXPECT_EQ(interpreter.evaluate(expr3), Literal(false)); // 7 <= 5
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
