#ifndef IOPERATION_H
#define IOPERATION_H
#include "pair.hpp"


class IOperation {
public:
    virtual const double operate(Pair operands) = 0;
    virtual ~IOperation() = 0;
};

#endif // IOPERATION_H
