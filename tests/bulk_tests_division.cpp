#include <gtest/gtest.h>
#include "../Calculator.h"

/**
 * Omdat er type-conversion nodig is van een Integer naar een double is deze test wat gedetailleerder uitgewerkt
 */
TEST(BulkTest, LoadTestDivision) {

    // ARRANGE
    Calculator calculator;
    for (int i = 0; i < 100; ++i) {
        for (int j = 1; j < 100; ++j) {
            double fI, fJ, expectedValue, realValue;

            // converteer parameters
            fI = (double) i;
            fJ = (double) j;

            // bepaal de uitkomst
            expectedValue = fI / fJ;

            // ACT: bepaal de uitkomsten van de calculator
            realValue = calculator.compute(fI, '/', fJ);

            // ASSERT: kijk of de verwachting uitkomt.
            EXPECT_DOUBLE_EQ(realValue, expectedValue);
        }
    }
}


TEST(BulkTest, LoadTestDivisionWithArray) {
    Calculator calculator;
    std::vector<std::tuple<double, double, double>> testCases = {
            {10.0, 2.0, 5.0},
            {100.0, 5.0, 20.0},
            {1.0, 3.0, 1.0 / 3.0},
            {7.0, 7.0, 1.0},
            {0.0, 1.0, 0.0}
    };

    for (const auto& [a, b, expected] : testCases) {
        double realValue = calculator.compute(a, '/', b);
        
        EXPECT_DOUBLE_EQ(realValue, expected);
    }
}
