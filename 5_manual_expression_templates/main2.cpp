#include <array>
#include <assert.h>

#include "sequence.hpp"

std::array<int, 5> a{{1, 2, 3, 4, 5}};

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
auto operator^(Sequence const& seq, unsigned pow)
{
    assert(pow == 2);

    return pow2_expr{seq};
}

int main()
{
    auto s = sequence{a};
    auto e = s ^ 2;

    return e(0);
}
