#include "divideoperation.hpp"

const double DivideOperation::operate(Pair operands) {
    return operands.getA() / operands.getB();
}
