#ifndef _POW_HPP
#define _POW_HPP

#include "discrete_sequence.hpp"

#include <boost/hana/integral_constant.hpp>
#include <cstdlib>

template<long long N, typename T>
auto power(T x) {
    if constexpr (N == 0) {
        return T{1};
    } else {
        return x * power<N-1>(x);
    }
};

template <long long N, typename UnderlyingSequence>
struct pow_expr
{
    constexpr explicit pow_expr(UnderlyingSequence const& seq) : seq{seq} {};

    constexpr unsigned operator()(size_t index) const {
        return power<N>(seq(index));
    }

    UnderlyingSequence const& seq;
};

template <typename Sequence, long long N>
constexpr auto operator^(Sequence const& seq, boost::hana::integral_constant<long long, N>)
{
    return pow_expr<N, Sequence>{seq};
}

#endif //_POW_HPP
