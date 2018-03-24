#ifndef _CALLABLE_HPP
#define _CALLABLE_HPP

#include <boost/yap/algorithm.hpp>
#include <boost/callable_traits/function_type.hpp>
#include <boost/callable_traits/return_type.hpp>
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

struct reduce_to_callable {
    template <typename CallableLeft, typename CallableRight>
    auto operator()(expr_tag<expr_kind::multiplies_assign>,
        lazy_invocation<CallableLeft>  left,
        lazy_invocation<CallableRight> right)
    {
        using arg_type_right    = std::tuple_element_t<0, boost::callable_traits::args_t<CallableRight>>;
        using return_type_right = boost::callable_traits::return_type_t<CallableRight>;
        using arg_type_left     = std::tuple_element_t<0, boost::callable_traits::args_t<CallableLeft>>;
        static_assert(std::is_convertible_v<return_type_right, arg_type_left>,
            "reduce_callables: return type can't be chained with arg type");

        return [left, right](arg_type_right arg) {
            return left.callable(right.callable(arg));
        };
    }

    template <typename CallableLeft, typename RightSubexpr>
    auto operator()(expr_tag<expr_kind::multiplies_assign>,
        lazy_invocation<CallableLeft> left,
        RightSubexpr rightSubexpr)
    {
        auto right = boost::yap::transform(rightSubexpr, reduce_to_callable{});

        using arg_type_right    = std::tuple_element_t<0, boost::callable_traits::args_t<decltype(right)>>;
        using return_type_right = boost::callable_traits::return_type_t<decltype(right)>;
        using arg_type_left     = std::tuple_element_t<0, boost::callable_traits::args_t<CallableLeft>>;
        static_assert(std::is_convertible_v<return_type_right, arg_type_left>,
            "reduce_to_callable: return type can't be chained with arg type");

        return [left, right](arg_type_right arg) {
            return left.callable(right(arg));
        };
    };
};

#endif //_CALLABLE_HPP
