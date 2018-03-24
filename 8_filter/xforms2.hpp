#ifndef _XFORMS_HPP
#define _XFORMS_HPP

#include <boost/yap/algorithm_fwd.hpp>

#include "range.hpp"
#include "filter2.hpp"
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

        return range{??{r.begin(), incr, deref},
                     ??{r.end(), incr, deref}};
    }
};

#endif //_XFORMS_HPP
