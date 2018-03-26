#ifndef _FILTER_HPP
#define _FILTER_HPP

#include "range.hpp"
#include "range_expr.hpp"

#include <boost/yap/algorithm.hpp>
#include <boost/callable_traits/args.hpp>
#include <boost/callable_traits/return_type.hpp>
#include <boost/callable_traits/function_type.hpp>

#include <type_traits>

template <typename Predicate>
struct filter_function
{
    Predicate predicate;
};

template <boost::yap::expr_kind Kind, typename Tuple>
struct filter_expr {
    constexpr static boost::yap::expr_kind kind = Kind;
    Tuple                                  elements;
};

template <typename Predicate>
constexpr auto filter(Predicate&& predicate)
{
    using arg_type    = boost::callable_traits::args_t<Predicate>;
    using return_type = boost::callable_traits::return_type_t<Predicate>;

    static_assert(std::tuple_size_v<arg_type> == 1,
        "Predicate argument for filter needs to take one argument");
    static_assert(std::is_same_v<return_type, bool>,
        "Predicate argument for filter needs to return a bool");

    return boost::yap::make_terminal<filter_expr>(filter_function<Predicate>{std::forward<Predicate>(predicate)});
}

#endif //_FILTER_HPP
