#include <stdexcept>
#include "divideoperation.hpp"

const double DivideOperation::operate(Pair operands) {
    if(operands.getB() == 0) throw std::invalid_argument("Division by zero");
    return operands.getA() / operands.getB();
}
