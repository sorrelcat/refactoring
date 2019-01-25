#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP
#include "pair.hpp"
#include "ioperation.hpp"

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
