#include "minusoperation.hpp"

const double MinusOperation::operate(Pair operands) {
    return operands.getA() - operands.getB();
}

