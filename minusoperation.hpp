#ifndef MINUSOPERATION_H
#define MINUSOPERATION_H
#include "ioperation.hpp"


class MinusOperation : public IOperation
{
public:
    const double operate(Pair operands);
};

#endif // MINUSOPERATION_H
