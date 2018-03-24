#include "scalars.hpp"
#include "filter3.hpp"
#include "boost/yap/print.hpp"
#include "xforms4.hpp"

using namespace boost::yap;

auto odd = [](unsigned x) { return x % 2 == 1; };
auto multipleOf3 = [](unsigned x) { return x % 3 == 0; };

int main()
{
    auto e = filter(multipleOf3) <<= filter(odd) <<= scalars<unsigned>{0,10};

    auto t = transform(e, xforms{});
    std::vector<int> v = t;

//    for (auto value : v) {
//        std::cout << value << std::endl;
//    }
}
