#include <gtest/gtest.h>
#include "../Calculator.h"
#include "../Parser.h"

TEST(CalculatorTest, Addition) {
    Calculator calculator;
    EXPECT_DOUBLE_EQ(calculator.compute(2.0, '+', 3.0), 5.0);
}

TEST(CalculatorTest, Subtraction) {
    Calculator calculator;
    EXPECT_DOUBLE_EQ(calculator.compute(5.0, '-', 2.0), 3.0);
}

TEST(CalculatorTest, Multiplication) {
    Calculator calculator;
    EXPECT_DOUBLE_EQ(calculator.compute(3.0, '*', 4.0), 12.0);
}

TEST(CalculatorTest, Division) {
    Calculator calculator;
    EXPECT_DOUBLE_EQ(calculator.compute(10.0, '/', 2.0), 5.0);
}

TEST(CalculatorTest, DivisionByZero) {
    Calculator calculator;
    EXPECT_THROW(calculator.compute(10.0, '/', 0.0), std::runtime_error);
}

TEST(ParserTest, ValidInput) {
    Parser parser;
    double op1, op2;
    char op;
    EXPECT_TRUE(parser.parse("12.5 + 7.3", op1, op, op2));
    EXPECT_DOUBLE_EQ(op1, 12.5);
    EXPECT_EQ(op, '+');
    EXPECT_DOUBLE_EQ(op2, 7.3);
}

TEST(ParserTest, InvalidInput) {
    Parser parser;
    double op1, op2;
    char op;
    EXPECT_FALSE(parser.parse("12.5++7.3", op1, op, op2));
}
