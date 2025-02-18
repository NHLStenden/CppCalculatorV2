#include <gtest/gtest.h>
#include "../Calculator.h"

TEST(BulkTest, LoadTestMultiplication) {
    Calculator calculator;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            double fI, fJ;
            fI = (double) i;
            fJ = (double) j;
            EXPECT_DOUBLE_EQ(calculator.compute(fI, '*', fJ), fI * fJ);
        }
    }

}

TEST(BulkTest, LoadTestMultiplication2) {
    Calculator calculator;
    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 1000; ++j) {
            double fI, fJ, expectedValue, realValue;
            fI = (double) i;
            fJ = (double) j;

            expectedValue = fI * fJ;
            realValue = calculator.compute(fI, '*', fJ);

            EXPECT_DOUBLE_EQ(realValue, expectedValue);
        }
    }

}


TEST(BulkTest, LoadTestMultiplication3) {
    Calculator calculator;
    for (int i = 0; i < 10000; ++i) {
        for (int j = 0; j < 10000; ++j) {
            double fI, fJ, expectedValue, realValue;
            fI = (double) i;
            fJ = (double) j;

            expectedValue = fI * fJ;
            realValue = calculator.compute(fI, '*', fJ);

            EXPECT_DOUBLE_EQ(realValue, expectedValue);
        }
    }

}


TEST(BulkTest, LoadTestMultiplication4) {
    Calculator calculator;
    for (int i = 0; i < 100000; ++i) {
        for (int j = 0; j < 100000; ++j) {
            double fI, fJ, expectedValue, realValue;
            fI = (double) i;
            fJ = (double) j;

            expectedValue = fI * fJ;
            realValue = calculator.compute(fI, '*', fJ);

            EXPECT_DOUBLE_EQ(realValue, expectedValue);
        }
    }

}

