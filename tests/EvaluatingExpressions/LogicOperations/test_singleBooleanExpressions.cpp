// SingleOperatorTokensExpressions.cpp
#include <gtest/gtest.h>
#include "Expression.h"
#include "Interpreter.h"


// Test GREATER (>) operator
TEST(InterpreterTest, GreaterOperator) {
    Interpreter interpreter;

    Expression* expr1 = new Binary(new Literal(5), Token(TokenType::GREATER), new Literal(3));
    Expression* expr2 = new Binary(new Literal(3), Token(TokenType::GREATER), new Literal(5));
    Expression* expr3 = new Binary(new Literal(5), Token(TokenType::GREATER), new Literal(5));

    EXPECT_EQ(interpreter.evaluate(expr1), Literal(true));  // 5 > 3
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(false)); // 3 > 5
    EXPECT_EQ(interpreter.evaluate(expr3), Literal(false)); // 5 > 5
}

// Test LESS (<) operator
TEST(InterpreterTest, LessOperator) {
    Interpreter interpreter;

    Expression* expr1 = new Binary(new Literal(3), Token(TokenType::LESS), new Literal(5));
    Expression* expr2 = new Binary(new Literal(5), Token(TokenType::LESS), new Literal(3));
    Expression* expr3 = new Binary(new Literal(5), Token(TokenType::LESS), new Literal(5));

    EXPECT_EQ(interpreter.evaluate(expr1), Literal(true));  // 3 < 5
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(false)); // 5 < 3
    EXPECT_EQ(interpreter.evaluate(expr3), Literal(false)); // 5 < 5
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}