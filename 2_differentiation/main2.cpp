#include "differentiator.hpp"

double function(double x) { return x * x; }
volatile double x = 1;

int main()
{
    differentiator firstDerivative{function};
    differentiator secondDerivative{firstDerivative};

    return secondDerivative(x);
}

// if we take the second derivative of a non-trivial function, the compiler should be able to optimize away some calls.
