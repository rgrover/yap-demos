//          Copyright Rohit Grover 2018 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef _DROP_HPP
#define _DROP_HPP

#include "range.hpp"
#include "range_expr.hpp"
#include <boost/yap/algorithm.hpp>

template <boost::yap::expr_kind Kind, typename Tuple>
struct drop_expr {
    constexpr static boost::yap::expr_kind kind = Kind;
    Tuple                                  elements;
};

BOOST_YAP_USER_BINARY_OPERATOR(shift_left_assign, drop_expr, range_expr)

struct drop_value
{
    size_t value;
};

constexpr auto drop(size_t n)
{
    return boost::yap::make_terminal<drop_expr>(drop_value{n});
}

#endif //_DROP_HPP
