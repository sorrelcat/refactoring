#include"calculator.hpp"
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
/*
 * Calculator by MK
*/
// Not obvious what is funciton result
void split(const std::string& str, std::vector<std::string>& container, char delim = ' ')
{
    std::stringstream ss(str);
    std::string token;
    // Not obvious that get line will fetch elements splitted by space
    while (std::getline(ss, token, delim)) {
        container.push_back(token);
    }
}

double calculate( const std::string input )
{
    std::vector<std::string> container;
    split ( input, container );
    auto a = std::stod( container[0]);
    auto b = std::stod( container[1]);
    char c = container[2][0];
    double result;
    switch (c)
    {
    case '+': result = a + b;
        break;
    case '-': result = a - b;
        break;
    case '*': result = a * b;
        break;
    case '/': result = a / b;
        break;
    }
    return result;
}
