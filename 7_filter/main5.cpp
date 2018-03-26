#include "scalars.hpp"
#include "filter3.hpp"
#include "xforms3.hpp"
#include "boost/yap/print.hpp"

using namespace boost::yap;

auto odd = [](unsigned x) { return x % 2 == 1; };

int main()
{
    auto e = filter(odd) <<= scalars<unsigned>{0, 10};

//  we should be able to string filter expressions
//  auto e = filter(multipleOf3) <<= filter(odd) <<= ...

    auto range = transform(e, xforms{});
    for (auto value : range) {
        std::cout << value << std::endl;
    }
}
