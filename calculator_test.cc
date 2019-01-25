#include <gtest/gtest.h>
#include "utilites.hpp"

TEST(MyFirstTest, MyFirstTestCase) {
    int x = 1;
    int y = 1;
    EXPECT_EQ(x, y);
    EXPECT_TRUE(x == y);
}

TEST(SplitTest, StringWithoutSpaces) {
    std::string s = "qwertyuiop";
    std::vector<std::string> v;
    v.push_back(s);
    EXPECT_EQ(v, split(s));
}

TEST(SplitTest, StringWithSpaces1) {
    std::string s = "qwe rty uiop";
    std::vector<std::string> v;
    v.push_back("qwe");
    v.push_back("rty");
    v.push_back("uiop");
    EXPECT_EQ(v, split(s));
}

TEST(SplitTest, StringWithSpaces2) {
    std::string s = "2 3 +";
    std::vector<std::string> v;
    v.push_back("2");
    v.push_back("3");
    v.push_back("+");
    EXPECT_EQ(v, split(s));
}

/*
TEST(CalculatorTest, TestOperatorPlus) {

    Calculator calc = new Calculator();
    auto result = calculate("2 2 +");
    EXPECT_DOUBLE_EQ(4, result);
}

TEST(CalculatorTest, TestOperatorMinus) {
    auto result = calculate("2 2 -");
    EXPECT_DOUBLE_EQ(4, result);
}

TEST(CalculatorTest, TestOperatorMultiply) {
    auto result = calculate("2 3 *");
    EXPECT_DOUBLE_EQ(6, result);
}

TEST(CalculatorTest, TestOperatorDivide) {
    auto result = calculate("6 2 /");
    EXPECT_DOUBLE_EQ(3, result);
}

TEST(CalculatorTest, TestZeroString) {
    auto result = calculate("");
    EXPECT_DOUBLE_EQ(std::invalid_argument, result);
}

TEST(CalculatorTest, TestWrongOperation) {
    auto result = calculate("3 6 %");
    EXPECT_DOUBLE_EQ(std::invalid_argument, result);
}

TEST(CalculatorTest, TestWrongOrder) {
    auto result = calculate("+ 3 6");
    EXPECT_DOUBLE_EQ(std::invalid_argument, result);
}

TEST(CalculatorTest, TestWrongOperands) {
    auto result = calculate("3 6 + 8 9");
    EXPECT_DOUBLE_EQ(std::invalid_argument, result);
}

TEST(CalculatorTest, TestWrongSymbols) {
    auto result = calculate("3 R 6");
    EXPECT_DOUBLE_EQ(std::invalid_argument, result);
}

TEST(CalculatorTest, TestLongString1) {
    auto result = calculate("3 4 * 2 / 6 - 8 +");
    EXPECT_DOUBLE_EQ(8, result);
}

TEST(CalculatorTest, TestLongString2) {
    auto result = calculate("5 4 + 2 - 6 * 2 /");
    EXPECT_DOUBLE_EQ(21, result);
}

TEST(CalculatorTest, TestLongString3) {
    auto result = calculate("9 4 - 5 / 6 * 8 +");
    EXPECT_DOUBLE_EQ(14, result);
}

TEST(CalculatorTest, TestRandomString) {
    auto result = calculate("gtrkgntrkgbrtkbgbrk");
    EXPECT_DOUBLE_EQ(std::invalid_argument, result);
}

TEST(CalculatorTest, TestDivizionByZero) {
    auto result = calculate("2 0 /");
    EXPECT_DOUBLE_EQ(std::invalid_argument, result);
}

TEST(CalculatorTest, TestStringWithInvalidStructure1) {
    auto result = calculate("2 0 // / /");
    EXPECT_DOUBLE_EQ(std::invalid_argument, result);
}

TEST(CalculatorTest, TestStringWithInvalidStructure2) {
    auto result = calculate("2 3 4");
    EXPECT_DOUBLE_EQ(std::invalid_argument, result);
}

TEST(CalculatorTest, TestStringWithInvalidStructure3) {
    auto result = calculate("2+3");
    EXPECT_DOUBLE_EQ(std::invalid_argument, result);
}

TEST(CalculatorTest, TestDouble) {
    auto result = calculate("3.5 6.7 +");
    EXPECT_DOUBLE_EQ(10.2, result);
}

TEST(CalculatorTest, TestDoublePlusOverflow) {
    auto result = calculate(" +");
    EXPECT_DOUBLE_EQ(new Result(0, 3), result);
}

TEST(CalculatorTest, TestDoubleMinusOverflow) {
    auto result = calculate("DBL_MAX -DBL_MAX -");
    EXPECT_DOUBLE_EQ(std::overflow_error, result);
}

TEST(CalculatorTest, TestDoubleMultiplyOverflow) {
    auto result = calculate("DBL_MAX DBL_MAX +");
    EXPECT_DOUBLE_EQ(std::overflow_error, result);
}

TEST(CalculatorTest, TestDoubleDivideOverflow) {
    auto result = calculate("DBL_MAX 0.5 +");
    EXPECT_DOUBLE_EQ(std::overflow_error, result);
}
*/


