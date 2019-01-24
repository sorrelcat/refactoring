#include "operation.hpp"

Operation::Operation()
{
public:
    virtual const double operate(Pair operands) = 0;
    virtual ~Operation() = 0;
}

