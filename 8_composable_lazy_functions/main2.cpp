#include "callable.hpp"
#include "xforms.hpp"
#include <boost/yap/print.hpp>
using namespace boost::yap;

auto squared = [](unsigned x) { return x * x; };
auto times2  = [](unsigned x) { return 2 * x; };
auto plus1   = [](unsigned x) { return x + 1; };

int main()
{
    auto e = apply(times2) *= apply(squared);

//    auto t = transform(e, reduce_to_callable{});
//    return t(2);
}
