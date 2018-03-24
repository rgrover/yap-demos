#include <iostream>

#include "boost/yap/expression.hpp"
#include "boost/yap/print.hpp"

using namespace boost::yap;

template <typename T>
using term = terminal<expression, T>;

int main()
{
    auto yap_expr = (term<double (*)(double)>{std::sqrt} + 8.0f) = 1;

    print(std::cout, yap_expr);

//    auto value = evaluate(yap_expr);??
    return 0;
}
