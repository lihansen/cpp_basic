#include "q.h"

// Given two integers, returns the result of the operation based on the given
// operator.
float CPPLib::Calculate(int a, int b, Operation operation) {
    float res;
    switch (operation)
    {
    case Operation::add/* constant-expression */:
        res = float(a+b);
        break;
    case Operation::subtract:
        res = float(a-b);
        break;
    case Operation:: division:
        if (b == float(0)){
            return float(__FLT_MAX__);
        }
        res = float(a/b);
        break;
    case Operation:: multiplication:
        res = float(a*b);
        break;
    case Operation::bitwise_AND:
        res = float(a&b);
        break;
    case Operation::bitwise_OR:
        res = float(a|b);
        break;
    case Operation::bitwise_XOR:
        res = float(a^b);
        break;
    case Operation::shift_right:
        res = float(a>>b);
        break;
    case Operation::shift_left:
        res = float(a<<b);
        break;
    default:
        break;
    }

    return res;
}
