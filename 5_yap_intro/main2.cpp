#include "boost/yap/expression.hpp"
#include "boost/yap/print.hpp"
#include <iostream>
using namespace boost::yap;

template <typename T>
using term = terminal<expression, T>;

int main()
{
    // but then yap's expression doesn't discriminate non-domain-specific expressions
    auto yap_expr = (term<double (*)(double)>{std::sqrt} + 8.0f) = 1;

    print(std::cout, yap_expr);

//    auto value = evaluate(yap_expr);??
    return 0;
}

/*
 * YAP can take care of capturing expresisons (and transforming them).
 * We can focus creating a domain-specific language (DSL).
 */
