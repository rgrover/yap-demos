#include "scalars.hpp"
//#include <vector>

using namespace boost::yap;

auto odd = [](unsigned x) { return x % 2 == 1; };

int main()
{
    auto e = filter(odd) <<= scalars<unsigned>{0,100};

//    static_assert(is_expr<decltype(e)>::value);
//    std::vector<int> v = transform(e, xforms);
}

// recall:
//   auto e =    ...
//           <<= filter(odd)
//           <<= scalars<unsigned>{0, 1, 100};
