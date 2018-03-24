#include "callable.hpp"
#include "xforms.hpp"
#include <boost/yap/print.hpp>
using namespace boost::yap;

auto squared = [](unsigned x){ return x * x; };
auto plusOne = [](unsigned x){ return x + 1; };

int main()
{
    /* recall this from
     *     auto e =     take(4)
     *              <<= map(apply(subtract1) *= apply(squared))   <--- function composition
     *              <<= filter(odd)
     *              <<= scalars<unsigned>{};
     */
    auto e = apply(plusOne) *= apply(squared);

//    expose<decltype(e)> i;
//    auto t = transform(e, reduce_to_callable{});
//    expose<decltype(t)> i;
}
