//          Copyright Rohit Grover 2018 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef _TAKE_HPP
#define _TAKE_HPP

#include "range.hpp"

#include <boost/yap/algorithm.hpp>
#include <boost/callable_traits/args.hpp>
#include <boost/callable_traits/return_type.hpp>
#include <boost/callable_traits/function_type.hpp>

#include <type_traits>

template <boost::yap::expr_kind Kind, typename Tuple>
struct take_expr {
    constexpr static boost::yap::expr_kind kind = Kind;
    Tuple                                  elements;
};

BOOST_YAP_USER_BINARY_OPERATOR(shift_left_assign, take_expr, range_expr)

struct take_value
{
    size_t n;
};

constexpr auto take(size_t n)
{
    return boost::yap::make_terminal<take_expr>(take_value{n});
}

#endif //_TAKE_HPP
