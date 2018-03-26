#include "scalars.hpp"
#include "filter3.hpp"
#include "xforms.hpp"
#include "boost/yap/print.hpp"

using namespace boost::yap;

auto odd = [](unsigned x) { return x % 2 == 1; };

int main()
{
    auto e = filter(odd) <<= scalars<unsigned>{0, 10};

    auto range = transform(e, xforms{});
//    for (auto value : range) {
//        std::cout << value << std::endl;
//    }
}
