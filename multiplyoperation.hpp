#ifndef MULTIPLYOPERATION_H
#define MULTIPLYOPERATION_H
#include "ioperation.hpp"
#include "pair.hpp"


class MultiplyOperation : public IOperation
{
public:
    const double operate(Pair operands);
};

#endif // MULTIPLYOPERATION_H
