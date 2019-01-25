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

TEST(CalculatorTest, TestOperatorPlus) {

    auto result = containerWorker("2 2 +");
    EXPECT_DOUBLE_EQ(4, result);
}

TEST(CalculatorTest, TestOperatorMinus) {
    auto result = containerWorker("2 2 -");
    EXPECT_DOUBLE_EQ(0, result);
}

TEST(CalculatorTest, TestOperatorMultiply) {
    auto result = containerWorker("2 3 *");
    EXPECT_DOUBLE_EQ(6, result);
}

TEST(CalculatorTest, TestOperatorDivide) {
    auto result = containerWorker("6 2 /");
    EXPECT_DOUBLE_EQ(3, result);
}

TEST(CalculatorTest, TestDouble) {
    auto result = containerWorker("3.5 6.7 +");
    EXPECT_DOUBLE_EQ(10.2, result);
}

TEST(CalculatorTest, TestLongString1) {
    auto result = containerWorker("3 4 * 2 / 6 - 8 +");
    EXPECT_DOUBLE_EQ(8, result);
}

TEST(CalculatorTest, TestLongString2) {
    auto result = containerWorker("5 4 + 2 - 6 * 2 /");
    EXPECT_DOUBLE_EQ(21, result);
}

TEST(CalculatorTest, TestLongString3) {
    auto result = containerWorker("9 4 - 5 / 6 * 8 +");
    EXPECT_DOUBLE_EQ(14, result);
}

TEST(CalculatorTest, TestZeroString) {
    EXPECT_THROW({containerWorker("");},
                 std::invalid_argument);
}

TEST(CalculatorTest, TestWrongOperation) {
    EXPECT_THROW({containerWorker("3 6 %");},
                 std::invalid_argument);
}

TEST(CalculatorTest, TestWrongOrder) {
    EXPECT_THROW({containerWorker("+ 3 6");},
                 std::invalid_argument);
}

TEST(CalculatorTest, TestWrongOperands) {
    EXPECT_THROW({containerWorker("3 6 + 8 9");},
                 std::invalid_argument);
}

TEST(CalculatorTest, TestWrongSymbols) {
    EXPECT_THROW({containerWorker("TestWrongSymbols");},
                 std::invalid_argument);
}

TEST(CalculatorTest, TestRandomString) {
    EXPECT_THROW({containerWorker("gtrkgntrkgbrtkbgbrk");},
                 std::invalid_argument);
}

TEST(CalculatorTest, TestDivizionByZero) {
    EXPECT_THROW({containerWorker("2 0 /");},
                 std::invalid_argument);
}

TEST(CalculatorTest, TestStringWithInvalidStructure) {
    EXPECT_THROW({containerWorker("2 0 // / /");},
                 std::invalid_argument);
}



/*


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


