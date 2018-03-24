#ifndef _XFORMS_HPP
#define _XFORMS_HPP

#include <boost/yap/algorithm_fwd.hpp>

#include "range.hpp"
#include "range_iterator.hpp"
#include "filter.hpp"
#include "drop.hpp"
#include "expose.hpp"

struct xforms
{
    template <typename Callable, typename RangeExpr>
    constexpr auto operator()(boost::yap::expr_tag<boost::yap::expr_kind::shift_left_assign>,
        map_function<Callable> m,
        RangeExpr rightSubexpr)
    {
        auto rightSubrange = boost::yap::transform(rightSubexpr, xforms{});

        using underlying_iterator     = typename decltype(rightSubrange)::iterator;
        using underlying_iterator_ref = std::add_lvalue_reference_t<underlying_iterator>;
        using underlying_value_type   = typename underlying_iterator::value_type;
        static_assert(std::is_invocable_v<Callable, underlying_value_type>,
            "mapping function incompatible with source range");

        auto callable = m.callable;

        auto incr = [end = rightSubrange.end()](underlying_iterator_ref iter) -> void {
            if (iter != end) {
                ++iter;
            }
        };
        auto deref = [xform = callable](underlying_iterator iter) {
            return xform(*iter);
        };

        return range{range_iterator{rightSubrange.begin(), incr, deref},
                     range_iterator{rightSubrange.end(), incr, deref}};
    }

    template <typename Callable, typename RangeIterator>
    constexpr auto operator()(boost::yap::expr_tag<boost::yap::expr_kind::shift_left_assign>,
        map_function<Callable>& m,
        range<RangeIterator> r)
    {
        using underlying_iterator     = RangeIterator;
        using underlying_iterator_ref = std::add_lvalue_reference_t<underlying_iterator>;
        using underlying_value_type   = typename underlying_iterator::value_type;
        static_assert(std::is_invocable_v<Callable, underlying_value_type>,
            "mapping function incompatible with source range");

        auto callable = m.callable;

        auto incr = [end = r.end](underlying_iterator_ref iter) -> void {
            if (iter != end) {
                ++iter;
            }
        };
        auto deref = [xform = callable](underlying_iterator iter) {
            return xform(*iter);
        };

        return range{range_iterator{r.begin, incr, deref},
                     range_iterator{r.end, incr, deref}};
    }

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

    template <typename RangeExpr>
    constexpr auto operator()(boost::yap::expr_tag<boost::yap::expr_kind::shift_left_assign>,
        take_value take,
        RangeExpr rightSubexpr)
    {
        auto rightSubrange = boost::yap::transform(rightSubexpr, xforms{});

        using underlying_iterator     = typename decltype(rightSubrange)::iterator;
        using underlying_iterator_ref = std::add_lvalue_reference_t<underlying_iterator>;

        auto incr = [remaining = take.n - 1, end = rightSubrange.end()](underlying_iterator_ref iter) mutable {
            if ((iter != end) && (remaining > 0)) {
                ++iter;
                --remaining;
            } else {
                iter.terminateIteration();
            }
        };
        auto deref = [](underlying_iterator iter) { return *iter; };

        return range{range_iterator{rightSubrange.begin(), incr, deref},
                     range_iterator{rightSubrange.end(), incr, deref}};
    }

    template <typename RangeIterator>
    constexpr auto operator()(boost::yap::expr_tag<boost::yap::expr_kind::shift_left_assign>,
        take_value take,
        range<RangeIterator> r)
    {
        using underlying_iterator     = RangeIterator;
        using underlying_iterator_ref = std::add_lvalue_reference_t<underlying_iterator>;

        auto incr = [remaining = take.n - 1, end = r.end()](underlying_iterator_ref iter) mutable {
            if ((iter != end) && (remaining > 0)) {
                ++iter;
                --remaining;
            } else {
                iter.terminateIteration();
            }
        };
        auto deref = [](underlying_iterator iter) { return *iter; };

        return range{range_iterator{r.begin(), incr, deref},
                     range_iterator{r.end(), incr, deref}};
    }

    template <typename Callable, typename Init, typename RangeExpr>
    constexpr auto operator()(boost::yap::expr_tag<boost::yap::expr_kind::shift_left_assign>,
        foldl_function<Callable, Init> foldl, RangeExpr rExpr)
    {
        auto range = boost::yap::transform(rExpr, xforms{});

        auto accum = foldl.init;
        for (auto value : range) {
            accum = foldl.callable(accum, value);
        }

        return accum;
    }

    template <typename RangeExpr>
    auto operator()(boost::yap::expr_tag<boost::yap::expr_kind::shift_left_assign>,
                    drop_value drop, RangeExpr rightSubexpr)
    {
        auto rightSubrange = boost::yap::transform(rightSubexpr, xforms{});

        using underlying_iterator     = typename decltype(rightSubrange)::iterator;
        using underlying_iterator_ref = std::add_lvalue_reference_t<underlying_iterator>;

        auto incr = [end = rightSubrange.end()](underlying_iterator_ref iter) {
            if (iter != end) {
                ++iter;
            }
        };
        auto deref = [](underlying_iterator iter) { return *iter; };

        /* progress the underlying iterator drop.value steps */
        while (drop.value && (rightSubrange.begin() != rightSubrange.end())) {
            --drop.value;
            incr(rightSubrange.begin());
        }

        return range{range_iterator{rightSubrange.begin(), incr, deref},
                     range_iterator{rightSubrange.end(), incr, deref}};
    };

    template <typename RangeIterator>
    constexpr auto operator()(boost::yap::expr_tag<boost::yap::expr_kind::shift_left_assign>,
                              drop_value drop,
                              range<RangeIterator> r)
    {
        using underlying_iterator     = RangeIterator;
        using underlying_iterator_ref = std::add_lvalue_reference_t<underlying_iterator>;

        auto incr = [end = r.end()](underlying_iterator_ref iter) {
            if (iter != end) {
                ++iter;
            }
        };
        auto deref = [](underlying_iterator iter) { return *iter; };

        /* progress the underlying iterator drop.value steps */
        while (drop.value && (r.begin() != r.end())) {
            --drop.value;
            incr(r.begin());
        }

        return range{range_iterator{r.begin(), incr, deref},
                     range_iterator{r.end(), incr, deref}};
    }
};

#endif //_XFORMS_HPP
