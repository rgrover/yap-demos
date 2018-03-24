//          Copyright Rohit Grover 2018 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef EXPR_TEMPLATES_SEQUENCE_HPP
#define EXPR_TEMPLATES_SEQUENCE_HPP

#include <cstdlib>

template <typename Sequence>
struct sequence
{
    constexpr explicit sequence(Sequence const& seq) : seq{seq} {};

    auto operator()(size_t index) const {
        return seq[index];
    }

    Sequence const& seq;
};
template <typename Sequence>
sequence(Sequence) -> sequence<Sequence>;

#endif //EXPR_TEMPLATES_SEQUENCE_HPP
