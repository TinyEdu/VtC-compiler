// GroupingExpressionsTest.cpp
#include <gtest/gtest.h>
#include "Expression.h"
#include "Interpreter.h"

// Test grouping expressions with addition and multiplication
TEST(InterpreterTest, GroupingWithAdditionAndMultiplication) {
    Interpreter interpreter;

    // (2 + 3) * 4
    Expression* expr1 = new Binary(
        new Grouping(new Binary(new Literal(2), Token(TokenType::PLUS), new Literal(3))),
        Token(TokenType::STAR),
        new Literal(4)
    );

    // 2 + (3 * 4)
    Expression* expr2 = new Binary(
        new Literal(2),
        Token(TokenType::PLUS),
        new Grouping(new Binary(new Literal(3), Token(TokenType::STAR), new Literal(4)))
    );

    EXPECT_EQ(interpreter.evaluate(expr1), Literal(20));  // (2 + 3) * 4 = 20
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(14));  // 2 + (3 * 4) = 14
}

// Test grouping expressions with subtraction and division
TEST(InterpreterTest, GroupingWithSubtractionAndDivision) {
    Interpreter interpreter;

    // (10 - 2) / 4
    Expression* expr1 = new Binary(
        new Grouping(new Binary(new Literal(10), Token(TokenType::MINUS), new Literal(2))),
        Token(TokenType::SLASH),
        new Literal(4)
    );

    // 10 - (2 / 2)
    Expression* expr2 = new Binary(
        new Literal(10),
        Token(TokenType::MINUS),
        new Grouping(new Binary(new Literal(2), Token(TokenType::SLASH), new Literal(2)))
    );

    EXPECT_EQ(interpreter.evaluate(expr1), Literal(2));   // (10 - 2) / 4 = 2
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(9));   // 10 - (2 / 2) = 9
}

// Test nested grouping
TEST(InterpreterTest, NestedGrouping) {
    Interpreter interpreter;

    // ((1 + 2) * (3 + 4))
    Expression* expr1 = new Grouping(
        new Binary(
            new Grouping(new Binary(new Literal(1), Token(TokenType::PLUS), new Literal(2))),
            Token(TokenType::STAR),
            new Grouping(new Binary(new Literal(3), Token(TokenType::PLUS), new Literal(4)))
        )
    );

    // ((5 + 3) / (4 - 2))
    Expression* expr2 = new Grouping(
        new Binary(
            new Grouping(new Binary(new Literal(5), Token(TokenType::PLUS), new Literal(3))),
            Token(TokenType::SLASH),
            new Grouping(new Binary(new Literal(4), Token(TokenType::MINUS), new Literal(2)))
        )
    );

    EXPECT_EQ(interpreter.evaluate(expr1), Literal(21));  // (1 + 2) * (3 + 4) = 21
    EXPECT_EQ(interpreter.evaluate(expr2), Literal(4));   // (5 + 3) / (4 - 2) = 4
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}