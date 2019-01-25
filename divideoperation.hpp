#ifndef DIVIDEOPERATION_H
#define DIVIDEOPERATION_H
#include "ioperation.hpp"


class DivideOperation : public IOperation
{
public:
    const double operate(Pair operands);
};

#endif // DIVIDEOPERATION_H
