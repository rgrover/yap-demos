#ifndef _FILTER_XFORMS_HPP
#define _FILTER_XFORMS_HPP

#include <boost/yap/algorithm_fwd.hpp>

#include "expose.hpp"
#include "range.hpp"

struct xforms
{
    template <typename E>
    auto operator()(E e) {
        ...
    }
};


#endif //_FILTER_XFORMS_HPP



//    template <typename Predicate, typename RangeIterator>
//    auto operator()(boost::yap::expr_tag<boost::yap::expr_kind::shift_left_assign>,
//        filter_function<Predicate> f, range<RangeIterator> range) {
//    }
