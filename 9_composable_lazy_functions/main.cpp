#include "scalars.hpp"
#include "filter.hpp"
#include "boost/yap/print.hpp"
#include "xforms.hpp"

using namespace boost::yap;

auto odd = [](unsigned x) { return x % 2 == 1; };
auto multipleOf3 = [](unsigned x) { return x % 3 == 0; };

int main()
{
    /* recall this? */
    auto e =
            <<= map(apply(subtract1) *= apply(squared))
            <<= filter(odd)
            <<= scalars<unsigned>{};

}
