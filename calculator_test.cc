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
    EXPECT_DOUBLE_EQ(new Result(4, true), result);
}

TEST(CalculatorTest, TestOperatorMinus) {
    auto result = calculate("2 2 -");
    EXPECT_DOUBLE_EQ(new Result(0, true), result);
}

TEST(CalculatorTest, TestOperatorMultiply) {
    auto result = calculate("2 3 *");
    EXPECT_DOUBLE_EQ(new Result(6, true), result);
}

TEST(CalculatorTest, TestOperatorDivide) {
    auto result = calculate("6 2 /");
    EXPECT_DOUBLE_EQ(new Result(3, true), result);
}

TEST(CalculatorTest, TestZeroString) {
    auto result = calculate("");
    EXPECT_DOUBLE_EQ(new Result(0, true), result);
}

TEST(CalculatorTest, TestWrongOperation) {
    auto result = calculate("3 6 %");
    EXPECT_DOUBLE_EQ(new Result(0, false), result);
}

TEST(CalculatorTest, TestWrongOrder) {
    auto result = calculate("+ 3 6");
    EXPECT_DOUBLE_EQ(new Result(0, false), result);
}

TEST(CalculatorTest, TestWrongOperands) {
    auto result = calculate("3 6 + 8 9");
    EXPECT_DOUBLE_EQ(new Result(0, false), result);
}

TEST(CalculatorTest, TestWrongSymbols) {
    auto result = calculate("3 R 6");
    EXPECT_DOUBLE_EQ(new Result(0, false), result);
}

TEST(CalculatorTest, TestLongString1) {
    auto result = calculate("3 4 * 2 / 6 - 8 +");
    EXPECT_DOUBLE_EQ(new Result(0, true), result);
}

TEST(CalculatorTest, TestLongString2) {
    auto result = calculate("5 4 + 2 - 6 * 2 /");
    EXPECT_DOUBLE_EQ(new Result(0, true), result);
}

TEST(CalculatorTest, TestLongString3) {
    auto result = calculate("9 4 - 5 / 6 * 8 +");
    EXPECT_DOUBLE_EQ(new Result(0, true), result);
}

TEST(CalculatorTest, TestRandomString) {
    auto result = calculate("gtrkgntrkgbrtkbgbrk");
    EXPECT_DOUBLE_EQ(new Result(0, false), result);
}

TEST(CalculatorTest, TestDivizionByZero) {
    auto result = calculate("2 0 /");
    EXPECT_DOUBLE_EQ(new Result(0, false), result);
}

TEST(CalculatorTest, TestStringWithInvalidStructure1) {
    auto result = calculate("2 0 // / /");
    EXPECT_DOUBLE_EQ(new Result(0, false), result);
}

TEST(CalculatorTest, TestStringWithInvalidStructure2) {
    auto result = calculate("2 3 4");
    EXPECT_DOUBLE_EQ(new Result(0, false), result);
}

TEST(CalculatorTest, TestStringWithInvalidStructure3) {
    auto result = calculate("2+3");
    EXPECT_DOUBLE_EQ(new Result(0, false), result);
}

TEST(CalculatorTest, TestDouble) {
    auto result = calculate("3.5 6.7 +");
    EXPECT_DOUBLE_EQ(new Result(0, true), result);
}

TEST(CalculatorTest, TestDoublePlusOverflow) {
    auto result = calculate("DBL_MAX DBL_MAX +");
    EXPECT_DOUBLE_EQ(new Result(0, false), result);
}

TEST(CalculatorTest, TestDoubleMinusOverflow) {
    auto result = calculate("DBL_MAX -DBL_MAX -");
    EXPECT_DOUBLE_EQ(new Result(0, false), result);
}

TEST(CalculatorTest, TestDoubleMultiplyOverflow) {
    auto result = calculate("DBL_MAX DBL_MAX +");
    EXPECT_DOUBLE_EQ(new Result(0, false), result);
}

TEST(CalculatorTest, TestDoubleDivideOverflow) {
    auto result = calculate("DBL_MAX 0.5 +");
    EXPECT_DOUBLE_EQ(new Result(0, false), result);
}



/*
operation with doubles
numeric limits with plus
numeric limits with minus
numeric limits with multiply
numeric limits with division
*/

