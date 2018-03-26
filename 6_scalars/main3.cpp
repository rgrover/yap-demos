#include "scalars.hpp"
#include <vector>
#include <iostream>

using namespace boost::yap;

int main()
{
    std::vector<int> v = scalars<unsigned>{0, 100};
    for (auto value : v) {
        std::cout << value << std::endl;
    }
}

// recall:
//   auto e =   ...
//           <<= filter(odd)
//           <<= scalars<unsigned>{0, 1, 100};
