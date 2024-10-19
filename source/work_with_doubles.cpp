#include "work_with_doubles.h"

#include <math.h>
#include <stdint.h>

#include "../include/my_asserts.h"

bool isInf(const double n)
{
    return isNan(n * 0.0);
}


bool isNan(const double n)
{
    uint64_t exponent = ((uint64_t)n >> 52) & 0x7FF;
    uint64_t mantissa = (uint64_t)n & 0xFFFFFFFFFFFFF;

    return (exponent == 0x7FF) && (mantissa != 0);
}


bool isFinite(const double n)
{
    return !isInf(n) && !isNan(n);
}


bool equatTwoDoubles(const double a, const double b)
{
    assertStrict(isFinite(a));
    assertStrict(isFinite(b));

    return (fabs(a - b) < EPS);
}


bool compareGreaterTwoDoubles(const double a, const double b)
{
    assertStrict(isFinite(a));
    assertStrict(isFinite(b));

    return (a - b > EPS);
}


bool compareLessTwoDoubles(const double a, const double b)
{
    assertStrict(isFinite(a));
    assertStrict(isFinite(b));

    return (b - a > EPS);
}
