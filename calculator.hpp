#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP
#include "plusoperation.hpp"
#include "minusoperation.hpp"
#include "multiplyoperation.hpp"
#include "divideoperation.hpp"
#include <stdexcept>

class Calculator {
private:
    Pair arguments;
    IOperation* operation;
public:
    IOperation* chooseOperation(char op);
    double calculate();
    Calculator(double a, double b, char op);
    void setAll(double a, double b, char op);
};

#endif
