#include "boost/yap/algorithm.hpp"
#include "scalar_iterator.hpp"
#include "range.hpp"
using namespace boost::yap;

template <typename T>
struct scalars
{
    constexpr static boost::yap::expr_kind kind = boost::yap::expr_kind::terminal;

    using tuple_element_type = range<scalar_iterator<T>>;
    boost::hana::tuple<tuple_element_type> elements;
};

int main()
{
    static_assert(is_expr<scalars<unsigned>>::value);

    /* let's try to use scalars{} in an expression */
}

// recall:
//   auto e =    ...
//           <<= filter(odd)
//           <<= scalars<unsigned>{0, 1, 100};
