#include <gtest/gtest.h>
#include "../Calculator.h"
#include "../Parser.h"

    TEST(CalculatorTest, Addition) {
        /** Arrange */
        Calculator calculator;

        /** Act */
        double result = calculator.compute(2.0, '+', 3.0)

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
