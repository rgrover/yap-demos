#ifndef _XFORMS_HPP
#define _XFORMS_HPP

#include <boost/yap/algorithm_fwd.hpp>

#include "range.hpp"
#include "range_iterator.hpp"
#include "filter.hpp"
#include "expose.hpp"

struct xforms
{
    template <typename Predicate, typename RangeIterator>
    auto operator()(boost::yap::expr_tag<boost::yap::expr_kind::shift_left_assign>,
        filter_function<Predicate> f, range<RangeIterator> r) {

        using underlying_iterator     = RangeIterator;
        using underlying_iterator_ref = std::add_lvalue_reference_t<underlying_iterator>;
        using underlying_value_type   = typename underlying_iterator::value_type;
        static_assert(std::is_invocable_v<Predicate, underlying_value_type>,
            "filter function incompatible with source range");

        auto predicate = f.predicate;

        auto incr = [predicate, end = r.end()](underlying_iterator_ref iter) -> void {
            ++iter;
            while ((iter != end) && !predicate(*iter)) {
                ++iter;
            }
        };
        auto deref = [](underlying_iterator iter) {
            return *iter;
        };

        /* Ensure that we start the underlying iter at a position which satisfies the predicate */
        if ((r.begin() != r.end()) && !predicate(*r.begin())) {
            incr(r.begin());
        }

        return range{range_iterator{r.begin(), incr, deref},
                     range_iterator{r.end(), incr, deref}};
    }

    template <typename Predicate, typename RangeExpr>
    auto operator()(boost::yap::expr_tag<boost::yap::expr_kind::shift_left_assign>,
        filter_function<Predicate> f,
        RangeExpr rightSubexpr) {
        auto rightSubrange = boost::yap::transform(rightSubexpr, xforms{});

        using underlying_iterator     = typename decltype(rightSubrange)::iterator;
        using underlying_iterator_ref = std::add_lvalue_reference_t<underlying_iterator>;
        using underlying_value_type   = typename underlying_iterator::value_type;
        static_assert(std::is_invocable_v<Predicate, underlying_value_type>,
            "filter function incompatible with source range");

        auto predicate = f.predicate;

        auto incr = [predicate, end = rightSubrange.end()](underlying_iterator_ref iter) -> void {
            ++iter;
            while ((iter != end) && !predicate(*iter)) {
                ++iter;
            }
        };
        auto deref = [](underlying_iterator iter) {
            return *iter;
        };

        /* Ensure that we start the underlying iter at a position which satisfies the predicate */
        if ((rightSubrange.begin() != rightSubrange.end()) && !predicate(*rightSubrange.begin())) {
            incr(rightSubrange.begin());
        }

        return range{range_iterator{rightSubrange.begin(), incr, deref},
                     range_iterator{rightSubrange.end(), incr, deref}};
    }
};

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

#endif //_FILTER_XFORMS_HPP
