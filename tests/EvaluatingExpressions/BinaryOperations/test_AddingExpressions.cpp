// interpreter_test.cpp
#include <gtest/gtest.h>
#include "Expression.h"
#include "Interpreter.h"

// Test adding positive numbers
TEST(InterpreterTest, AddsPositiveNumbers) {
  Interpreter interpreter;
  Binary* expr1 = new Binary(new Literal(100), Token(TokenType::PLUS),
                             new Literal(1111111123));
  Binary* expr2 =
      new Binary(new Literal(0), Token(TokenType::PLUS), new Literal(0));
  Binary* expr3 =
      new Binary(new Literal(2), Token(TokenType::PLUS), new Literal(213));

  EXPECT_EQ(interpreter.evaluate(expr1), Literal(1111111223));
  EXPECT_EQ(interpreter.evaluate(expr2), Literal(0));
  EXPECT_EQ(interpreter.evaluate(expr3), Literal(215));
}

// Test adding negative numbers
TEST(InterpreterTest, AddsNegativeNumbers) {
  Interpreter interpreter;
  Binary* expr1 =
      new Binary(new Literal(-5), Token(TokenType::PLUS), new Literal(-1));
  Binary* expr2 = new Binary(new Literal(-4), Token(TokenType::PLUS),
                             new Literal(-111111116));
  Binary* expr3 =
      new Binary(new Literal(-1000), Token(TokenType::PLUS), new Literal(-213));

  EXPECT_EQ(interpreter.evaluate(expr1), Literal(-6));
  EXPECT_EQ(interpreter.evaluate(expr2), Literal(-111111120));
  EXPECT_EQ(interpreter.evaluate(expr3), Literal(-1213));
}

// Test adding positive and negative numbers
TEST(InterpreterTest, AddsPositiveAndNegativeNumbers) {
  Interpreter interpreter;
  Binary* expr1 =
      new Binary(new Literal(122), Token(TokenType::PLUS), new Literal(-1));
  Binary* expr2 = new Binary(new Literal(3), Token(TokenType::PLUS),
                             new Literal(-1111111116));
  Binary* expr3 =
      new Binary(new Literal(10), Token(TokenType::PLUS), new Literal(-213));

  EXPECT_EQ(interpreter.evaluate(expr1), Literal(121));
  EXPECT_EQ(interpreter.evaluate(expr2), Literal(-1111111113));
  EXPECT_EQ(interpreter.evaluate(expr3), Literal(-203));

  Binary* expr4 =
      new Binary(new Literal(-122), Token(TokenType::PLUS), new Literal(21));
  Binary* expr5 = new Binary(new Literal(-3), Token(TokenType::PLUS),
                             new Literal(1111111116));
  Binary* expr6 =
      new Binary(new Literal(-10), Token(TokenType::PLUS), new Literal(213));

  EXPECT_EQ(interpreter.evaluate(expr1), Literal(121));
  EXPECT_EQ(interpreter.evaluate(expr2), Literal(1111111113));
  EXPECT_EQ(interpreter.evaluate(expr3), Literal(-203));
}
