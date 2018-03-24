#include "scalars.hpp"
//#include <vector>

using namespace boost::yap;

int main()
{
    auto e = scalars<unsigned>{0,100};

//    static_assert(is_expr<decltype(e)>::value);
//    std::vector<int> v = scalars<unsigned>{0,100};
}

// recall:
//   auto e =   ...
//           <<= filter(odd)
//           <<= scalars<unsigned>{0, 1, 100};
