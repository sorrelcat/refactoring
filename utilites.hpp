#ifndef UTILITES_HPP
#define UTILITES_HPP
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "calculator.hpp"

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

#endif // UTILITES_HPP

