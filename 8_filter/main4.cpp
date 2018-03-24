#include "scalars.hpp"
#include "filter3.hpp"
#include "boost/yap/print.hpp"
#include "xforms3.hpp"

using namespace boost::yap;

auto odd = [](unsigned x) { return x % 2 == 1; };

int main()
{
    auto e = filter(odd) <<= scalars<unsigned>{0,10};

//    auto t = transform(e, xforms{});
//    std::vector<int> v = t;
}
