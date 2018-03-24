#include <iostream>

#include "boost/yap/expression.hpp"
#include "boost/yap/print.hpp"

using namespace boost::yap;

int main()
{
    auto e = make_terminal<double (*)(double)>(std::sqrt)(3) + 8.0f;

//    print(std::cout, e);
//    auto value = evaluate(e);

    return 0;
}
