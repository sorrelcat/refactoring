#include"calculator.hpp"
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
/*
 * Calculator by MK
*/
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

enum CalcState {
    Success,
    DivisionByZero,
    DoubleOverflow
};

struct Result {
    double result;
    bool state;
    Result(double d , bool b): result(d = 0), state(b = true) {}
};

Result containerWorker(const std::vector<std::string> container) {
    if(container.size() < 3) return new
}


Result calculate( const std::string input )
{
    Result t;
    int a, b;
    char op;
    std::vector<std::string> container = split (input);
    // cycle for string that can contain more than 3 elements
    // catch errors: less than 3 elements, not 3+2*n elements
    // catch errors: not double or not operation symbol

    if(container.size()) a = container[0];
    for(auto it : container) {

        auto b = std::stod(*it++);
        auto c = container[2][0];
        double result;
        switch (c)
        {
        case '+': result = a + b;
            break;
        case '-': result = a - b;
            break;
        case '*': result = a * b;
            break;
        //catch error: division by zero
        case '/': result = a / b;
            break;
        }
    }
    return result;
}
