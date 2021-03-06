#ifndef _FIXED_SEQUENCE_HPP
#define _FIXED_SEQUENCE_HPP

#include <cstdlib>

template <typename Sequence>
struct discrete_sequence
{
    constexpr explicit discrete_sequence(Sequence const& seq) : seq{seq} {};

    auto operator()(size_t index) const {
        return seq[index];
    }

    Sequence const& seq;
};

#endif //_FIXED_SEQUENCE_HPP
