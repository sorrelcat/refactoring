#include "multiplyoperation.hpp"


const double MultiplyOperation::operate(Pair operands) {
    return operands.getA() * operands.getB();
}
