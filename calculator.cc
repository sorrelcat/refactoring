#include"calculator.hpp"
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
/*
 * Calculator by MK
*/

Result calculate(const double a, const double b, const char op);

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
    SomeError,
    Success,
    DivisionByZero,
    DoubleOverflow,
    ErrorString
};

struct Result {
    double value;
    CalcState state;
    Result(double d , CalcState s): value(d = 0), state(s = CalcState.SomeError) {}
};

Result containerWorker(const std::string input) {

    std::vector<std::string> container = split (input);

    int n = container.size();
    double a = 0, b = 0;
    char op = '';

    if(n < 3) return new Result(0, CalcState.ErrorString);
    if((n - 3) % 2) return new Result(0, CalcState.ErrorString);

    Result result = new Result();

    for(int i = 0; i < n; i++) {
        if(n - i == 2) {
            a = result.value;
        }
        else {
            try {
                a = std::stod(container[i]);
            }
            catch(Exception e) {
                return new Result(0, CalcState.ErrorString);
            }
        }
        try{
            b = std::stod(container[i]);
            op = container[i+1][0];
            result = calculate(result.value, b, op);
        }
        catch(Exception e) {
            return new Result(0, CalcState.ErrorString);
        }
    }
    return result;
}

Result calculate(const double a, const double b, const char op)
{
    Result result = new result(0, 1);
    double epsilon = std::numeric_limits<double>::epsilon();
    switch (op)
        {
            case '+':
                if(abs(a) - DBL_MAX <= epsilon || abs(b) - DBL_MAX <= epsilon)
                {
                    return new Result(0, 3);
                }
                result.value = a + b;
                break;
            case '-': result = a - b;
                break;
            case '*': result = a * b;
                break;
            case '/':
                if(b == 0) {
                    return new Result(0, 2);
                }
                result.value = a / b;
                break;
            default:
                return new Result(0, 4);
    }
    return result;
}
