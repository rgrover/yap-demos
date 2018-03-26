#ifndef _CALLABLE_HPP
#define _CALLABLE_HPP

#include <boost/yap/algorithm.hpp>
#include <boost/callable_traits/function_type.hpp>
#include <boost/callable_traits/args.hpp>

using namespace boost::yap;
using boost::callable_traits::function_type_t;

template <boost::yap::expr_kind Kind, typename Tuple>
struct callable_expr {
    constexpr static boost::yap::expr_kind kind = Kind;
    Tuple                                  elements;
};

BOOST_YAP_USER_BINARY_OPERATOR(multiplies_assign, callable_expr, callable_expr);

template <typename Callable>
struct lazy_invocation
{
    Callable callable;
};

template <typename Callable, typename = function_type_t<Callable>>
constexpr auto apply(Callable&& callable)
{
    using arg_type = boost::callable_traits::args_t<Callable>;

    static_assert(std::tuple_size_v<arg_type> == 1, "Callable argument for map needs to take one argument");

    return
        boost::yap::make_terminal<callable_expr>(
            lazy_invocation<Callable>{std::forward<Callable>(callable)}
        );
}

#endif //_CALLABLE_HPP
