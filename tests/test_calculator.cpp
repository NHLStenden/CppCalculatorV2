#include <gtest/gtest.h>
#include "../Calculator.h"
#include "../Parser.h"

TEST(CalculatorTest, Addition) {
    /** Arrange */
    Calculator calculator;

    /** Act */
    double result = calculator.compute(2.0, '+', 3.0);

    /** Assert */
    EXPECT_DOUBLE_EQ(result, 5.0);
}

TEST(CalculatorTest, Subtraction) {
    /** Arrange */
    Calculator calculator;

    /** Act + Assert */
    EXPECT_DOUBLE_EQ(calculator.compute(5.0, '-', 2.0), 3.0);
}

TEST(CalculatorTest, Multiplication) {
    /** Arrange, Act, Assert */
    EXPECT_DOUBLE_EQ(Calculator().compute(3.0, '*', 4.0), 12.0);
}

TEST(CalculatorTest, Division) {
    EXPECT_DOUBLE_EQ(Calculator().compute(10.0, '/', 2.0), 5.0);
}

TEST(CalculatorTest, DivisionByZero) {
    EXPECT_THROW(Calculator().compute(10.0, '/', 0.0), std::runtime_error);
}
