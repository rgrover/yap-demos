#ifndef _POW_HPP
#define _POW_HPP

#include "discrete_sequence.hpp"
#include <cstdlib>

template <typename UnderlyingSequence>
struct pow_expr
{
    constexpr explicit pow_expr(UnderlyingSequence const& seq, unsigned pow) :
        seq{seq}, pow{pow} {};

    constexpr unsigned operator()(size_t index) const {
        auto acc = seq(index);
        for (auto i = pow - 1; i; --i) {
            acc *= seq(index);
        }
        return acc;
    }

    UnderlyingSequence const& seq;
    unsigned                  pow;
};

template <typename Sequence>
constexpr auto operator^(Sequence const& seq, unsigned pow)
{
    return pow_expr{seq, pow};
}

#endif //_POW_HPP
