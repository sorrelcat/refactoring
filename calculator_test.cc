#include <gtest/gtest.h>
#include "calculator.h"

TEST(MyFirstTest, MyFirstTestCase) {
    int x = 1;
    int y = 1;
    EXPECT_EQ(x, y);
    EXPECT_TRUE(x == y);
}

TEST(CalculatorTest, TestOperatorPlus) {
    auto result = calculate("2 2 +");
    EXPECT_DOUBLE_EQ(4, result);
}

TEST(CalculatorTest, TestOperatorMinus) {
    auto result = calculate("2 2 -");
    EXPECT_DOUBLE_EQ(0, result);
}

TEST(CalculatorTest, TestOperatorMultiply) {
    auto result = calculate("2 3 *");
    EXPECT_DOUBLE_EQ(6, result);
}

TEST(CalculatorTest, TestOperatorDivide) {
    auto result = calculate("6 2 /");
    EXPECT_DOUBLE_EQ(3, result);
}

