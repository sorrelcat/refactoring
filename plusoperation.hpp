#ifndef PLUSOPERATION_H
#define PLUSOPERATION_H
#include "ioperation.hpp"


class PlusOperation : public IOperation
{
public:
    const double operate(Pair operands);
};

#endif // PLUSOPERATION_H
