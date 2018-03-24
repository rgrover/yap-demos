#include "boost/yap/algorithm.hpp"

using namespace boost::yap;

/* An expression contains a 'kind' (of type expr_kind) and 'elements' made from hana::tuple */

template <typename T>
struct scalars
{
    constexpr static boost::yap::expr_kind kind = boost::yap::expr_kind::terminal;

    using tuple_element_type = ??;
    boost::hana::tuple<tuple_element_type> elements;
};

int main()
{
//    static_assert(is_expr<scalars<unsigned>>::value);
}

// recall:
//   auto e =    ...
//           <<= filter(odd)
//           <<= scalars<unsigned>{0, 1, 100};
