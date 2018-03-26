#include "scalars.hpp"
#include "filter3.hpp"

using namespace boost::yap;

auto odd = [](unsigned x) { return x % 2 == 1; };
auto multipleOf3 = [](unsigned x) { return x % 3 == 0; };

int main()
{
    auto e = filter(odd) <<= scalars<unsigned>{0, 10};

// In order to be useful, the above expression needs to be transformed into a range.
//    auto t = transform(e, ...);
}
