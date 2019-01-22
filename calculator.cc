#include "calculator.h"

#include <sstream>
#include <vector>
#include <stack>

std::vector<std::string> split(const std::string &s, char delim);

double calculate(const std::string& eval)
{
    auto splittedFormula = split(eval, ' ');
    std::stack<double> result;

    for(auto& elem : splittedFormula)
    {
        if (elem == "*")
        {
            double second = result.top();
            result.pop();
            double first = result.top();
            result.pop();
            result.push(first * second);
        }
        else if (elem == "+")
        {
            double second = result.top();
            result.pop();
            double first = result.top();
            result.pop();
            result.push(first + second);
        }
        else if (elem == "-")
        {
            double second = result.top();
            result.pop();
            double first = result.top();
            result.pop();
            result.push(first - second);
        }
        else if (elem == "/")
        {
            double second = result.top();
            result.pop();
            double first = result.top();
            result.pop();
            result.push(first / second);
        }
        else
        {
            double res =  std::stod(elem);
            result.push(res);
        }
    }

    return result.top();
}

std::vector<std::string> split(const std::string &s, char delim)
{
    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> elems;

    while (std::getline(ss, item, delim)) {
        elems.push_back(std::move(item));
    }
    return elems;
}
