#include "discrete_sequence.hpp"
#include <array>

std::array<int, 5> a{{1, 2, 3, 4, 5}};

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
auto operator^(Sequence const& seq, unsigned pow)
{
    return pow_expr{seq, pow};
}

int main()
{
    auto s = discrete_sequence{a};
    auto e = s ^ 2;

    return e(0);
}
