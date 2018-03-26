//          Copyright Rohit Grover 2018 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef RANGES_FOLD_HPP
#define RANGES_FOLD_HPP


#include "range.hpp"
#include "callable.hpp"

#include <boost/yap/algorithm.hpp>
#include <boost/callable_traits/args.hpp>
#include <boost/callable_traits/return_type.hpp>
#include <boost/callable_traits/function_type.hpp>

#include <type_traits>

template <boost::yap::expr_kind Kind, typename Tuple>
struct single_value_expr {
    constexpr static boost::yap::expr_kind kind = Kind;
    Tuple                                  elements;
};

template <boost::yap::expr_kind Kind, typename Tuple>
struct foldl_expr {
    constexpr static boost::yap::expr_kind kind = Kind;
    Tuple                                  elements;
};

BOOST_YAP_USER_BINARY_OPERATOR(shift_left_assign, foldl_expr, single_value_expr)

template <typename Callable, typename Init>
struct foldl_function
{
    Callable callable;
    Init     init;
};

template <typename Callable, typename Init, typename = boost::callable_traits::function_type_t<Callable>>
constexpr auto foldl(Callable&& callable, Init&& init)
{
    using args_type   = boost::callable_traits::args_t<Callable>;
    using return_type = boost::callable_traits::return_type_t<Callable>;

    static_assert(std::tuple_size_v<args_type> == 2,
        "Callable argument for fold needs to take two arguments");
    static_assert(std::is_convertible_v<std::tuple_element_t<0, args_type>, Init>,
        "Initial value passed to fold needs to be convertible to the argument of the fold function");
    static_assert(!std::is_same_v<return_type, void>,
        "Callable argument for foldl needs to return a non-void type");

    return
        boost::yap::make_terminal<foldl_expr>(
            foldl_function<Callable, Init>{
                std::forward<Callable>(callable), std::forward<Init>(init)
            }
        );
}

#endif //RANGES_FOLD_HPP
