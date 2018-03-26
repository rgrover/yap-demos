#include "scalars.hpp"
#include "filter3.hpp"
#include "xforms5.hpp"
#include "boost/yap/print.hpp"

using namespace boost::yap;

auto odd = [](unsigned x) { return x % 2 == 1; };
auto multipleOf3 = [](unsigned x) { return x % 3 == 0; };

int main()
{
    auto e = filter(multipleOf3) <<= filter(odd) <<= scalars<unsigned>{0,10};

    auto range = transform(e, xforms{});
    for (auto value : range) {
        std::cout << value << std::endl;
    }
}
