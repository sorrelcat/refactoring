#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "plusoperation.hpp"
#include "minusoperation.hpp"
#include "multiplyoperation.hpp"
#include "divideoperation.hpp"
#include "pair.hpp"
#include "calculator.hpp"

//https://github.com/LuxoftAKutsan/calculator

std::vector<std::string> split(const std::string& str, char delim = ' ')
{
    std::vector<std::string> container;
    std::stringstream ss(str);
    std::string token;
    // Not obvious that get line will fetch elements splitted by space
    while (std::getline(ss, token, delim)) {
        container.push_back(token);
    }
    return container;
}

double containerWorker(const std::string input) {

    std::vector<std::string> container = split (input);

    int n = container.size();
    double a = 0, b = 0;
    char op = ' ';

    if(n < 3) throw std::invalid_argument("Too short string");
    if((n - 3) % 2) throw std::invalid_argument("String with incorrect number of arguments");

    try {
        a = std::stod(container[0]);
        b = std::stod(container[1]);
        op = container[2][0];
    }
    catch (std::exception e) {
        throw std::invalid_argument ("Can't read arguments");
    }

    Calculator calc(a, b, op);

    double result = calc.calculate();

    int i = 2;
    while(i < n) {
        b = std::stod(container[i]);
        op = container[i+1][0];
        i += 2;
        calc.setAll(a, b, op);
        result = calc.calculate();
    }

    return result;
}

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

