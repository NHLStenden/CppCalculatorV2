#include <gtest/gtest.h>
#include "../Calculator.h"
#include "../Parser.h"

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
