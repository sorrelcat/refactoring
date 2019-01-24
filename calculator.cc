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

double calculate(double, double, char);
IOperation chooseOperation(char op);

double containerWorker(const std::string input) {

    std::vector<std::string> container = split (input);

    int n = container.size();
    double a = 0, b = 0;
    char op = '';

    if(n < 3) throw std::invalid_argument("Too short string");
    if((n - 3) % 2) throw std::invalid_argument("String with incorrect number of arguments");

    try {
        a = std::stod(container[0]);
        b = std::stod(container[1]);
        op = container[2][0];
    }
    catch (Exception e) {
        throw std::invalid_argument;
    }

    IOperation operation = chooseOperation(op);
    double result = calculate(a, b, operation);

    int i = 2;
    while(i < n) {
        b = std::stod(container[i]);
        op = container[i+1];
        operation = chooseOperation(op);
        i += 2;
        result = calculate(result, b, op);
    }

    return result;
}

double calculate(double a, double b, IOperation op) {

    Pair arguments = new Pair(a, b);
    return op.operate(arguments);
}

IOperation chooseOperation(char op) {
    switch(op) {
        case '+': return new PlusOperation();
        case '-': return new MinusOperation();
        case '*': return new MultiplyOperation();
        case '/': return new DivideOperation();
        default: throw std::invalid_argument;
    }
}

