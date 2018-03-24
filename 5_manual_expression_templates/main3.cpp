#include <array>

#include "sequence.hpp"
#include "pow2.hpp"

template <typename UnderlyingExpr>
struct multiply_expr
{
    constexpr explicit multiply_expr(unsigned mult, UnderlyingExpr const& expr) : mult{mult}, expr{expr} {};

    unsigned operator()(size_t index) const {
        return mult * expr(index);
    }

    unsigned mult;
    UnderlyingExpr const& expr;
};

template <typename UnderlyingSequence>
auto operator*(unsigned mult, pow2_expr<UnderlyingSequence> const& pow)
{
    return multiply_expr{mult, pow};
}

std::array<int, 5> a{{1, 2, 3, 4, 5}};

int main()
{
    auto s = sequence(a);
    auto e = 2 * (s ^ 2);

    return e(0);
}
