#ifndef _RANGE_EXPR_HPP
#define _RANGE_EXPR_HPP

#include "boost/yap/algorithm.hpp"

template <boost::yap::expr_kind Kind, typename Tuple>
struct range_expr
{
    constexpr static boost::yap::expr_kind kind = Kind;
    Tuple                                  elements;
};

#endif //_RANGE_EXPR_HPP
