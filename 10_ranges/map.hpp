//          Copyright Rohit Grover 2018 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef RANGES_MAP_HPP
#define RANGES_MAP_HPP

#include "range.hpp"
#include "range_expr.hpp"
#include "callable.hpp"

#include <boost/yap/algorithm.hpp>
#include <boost/callable_traits/args.hpp>
#include <boost/callable_traits/return_type.hpp>
#include <boost/callable_traits/function_type.hpp>

#include <type_traits>

template <boost::yap::expr_kind Kind, typename Tuple>
struct map_expr {
    constexpr static boost::yap::expr_kind kind = Kind;
    Tuple                                  elements;
};

BOOST_YAP_USER_BINARY_OPERATOR(shift_left_assign, map_expr, range_expr)

template <typename Callable>
struct map_function
{
    Callable callable;
};

template <typename Callable, typename = boost::callable_traits::function_type_t<Callable>>
constexpr auto map(Callable&& callable)
{
    using arg_type    = boost::callable_traits::args_t<Callable>;
    using return_type = boost::callable_traits::return_type_t<Callable>;

    static_assert(std::tuple_size_v<arg_type> == 1,
        "Callable argument for map needs to take one argument");
    static_assert(!std::is_same_v<return_type, void>,
        "Callable argument for map needs to return a non-void type");

    return boost::yap::make_terminal<map_expr>(map_function<Callable>{std::forward<Callable>(callable)});
}

template <boost::yap::expr_kind Kind, typename Tuple>
constexpr auto map(callable_expr<Kind, Tuple> expr)
{
    auto callable = boost::yap::transform(expr, reduce_to_callable{});

    using arg_type    = boost::callable_traits::args_t<decltype(callable)>;
    using return_type = boost::callable_traits::return_type_t<decltype(callable)>;

    static_assert(std::tuple_size_v<arg_type> == 1,
        "Callable argument for map needs to take one argument");
    static_assert(!std::is_same_v<return_type, void>,
        "Callable argument for map needs to return a non-void type");

    return boost::yap::make_terminal<map_expr>(map_function<decltype(callable)>{std::forward<decltype(callable)>(callable)});
}

#endif //RANGES_MAP_HPP
