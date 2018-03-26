#include "scalars.hpp"
#include "filter2.hpp"

#include "boost/yap/print.hpp"

using namespace boost::yap;

auto odd = [](unsigned x) { return x % 2 == 1; };

int main()
{
    auto e = filter(odd);

//    print(std::cout, e);
//    static_assert(is_expr<decltype(e)>::value);
}

// recall:
//   auto e =    ...
//           <<= filter(odd)
//           <<= scalars<unsigned>{0, 1, 100};
//
// filter_expr needs to combine with range-like expressions
