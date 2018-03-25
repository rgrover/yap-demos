#include "discrete_sequence.hpp"
#include "pow2.hpp"
#include <boost/hana/integral_constant.hpp>
#include <array>

using namespace boost::hana::literals;

std::array<int, 5> a{{1, 2, 3, 4, 5}};

template <typename UnderlyingExpr>
struct multiply_expr
{
    constexpr explicit multiply_expr(unsigned mult, UnderlyingExpr const& expr) :
        mult{mult}, expr{expr} {};

    constexpr auto operator()(size_t index) const {
        return mult * expr(index);
    }

    unsigned              mult;
    UnderlyingExpr const& expr;
};

template <long long N, typename UnderlyingSequence>
constexpr auto operator*(unsigned mult, pow_expr<N, UnderlyingSequence> const& pow)
{
    return multiply_expr{mult, pow};
}

int main()
{
    auto s = discrete_sequence{a};
    auto e = 2 * (s ^ 2_c);

    return e(0);
}
