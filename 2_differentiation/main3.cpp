#include "differentiator.hpp"
#include <cmath>

double function(double x) { return std::sin(x); }
volatile double x = 1;

int main()
{
    differentiator firstDerivative{function};
    differentiator secondDerivative{firstDerivative};

    return secondDerivative(x);
}

// in some cases the compiler may be unable to perform the expected optimizations due to lack of information.
