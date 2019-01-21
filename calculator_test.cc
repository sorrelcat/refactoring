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
    EXPECT_EQ(4, result);
}
