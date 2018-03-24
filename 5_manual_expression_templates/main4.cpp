#include <array>

#include "sequence.hpp"
#include "pow2.hpp"
#include "multiply.hpp"

std::array<int, 5> a{{1, 2, 3, 4, 5}};

template <typename UnderlyingExpr>
struct add_expr
{
    constexpr explicit add_expr(UnderlyingExpr const& expr, unsigned value) : expr{expr}, value{value} {};

    auto operator()(size_t index) const {
        return expr(index) + value;
    }

    UnderlyingExpr const& expr;
    unsigned value;
};

template <typename UnderlyingExpr>
auto operator+(multiply_expr<UnderlyingExpr> const& m, unsigned value)
{
    return add_expr{m, value};
}

int main()
{
    auto s = sequence(a);
    auto e = (2 * (s ^ 2)) + 1;

    auto x = e(0);
    return x;
}
