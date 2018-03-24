//          Copyright Rohit Grover 2018 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef EXPR_TEMPLATES_POW2_HPP
#define EXPR_TEMPLATES_POW2_HPP

#include <assert.h>
#include <cstdlib>

#include "sequence.hpp"

template <typename UnderlyingSequence>
struct pow2_expr
{
    constexpr explicit pow2_expr(UnderlyingSequence const& seq) : seq{seq} {};

    unsigned operator()(size_t index) const {
        return seq(index) * seq(index);
    }

    UnderlyingSequence const& seq;
};

template <typename Sequence>
auto operator^(sequence<Sequence> const& seq, unsigned pow)
{
    assert(pow == 2);

    return pow2_expr{seq};
}


#endif //EXPR_TEMPLATES_POW2_HPP
