#include "calculator.hpp"

Calculator::Calculator (double a = 0, double b = 0, char op = '+'){
    setAll(a, b, op);
}

void Calculator::setAll(double a, double b, char op) {
    arguments.setA(a);
    arguments.setB(b);
    operation = chooseOperation(op);
}

double Calculator::calculate() {
    return operation->operate(arguments);
}

IOperation* Calculator::chooseOperation(char op) {
    switch(op) {
        case '+': return new PlusOperation();
        case '-': return new MinusOperation();
        case '*': return new MultiplyOperation();
        case '/': return new DivideOperation();
        default: throw std::invalid_argument("Can't read operation sign");
    }
}

