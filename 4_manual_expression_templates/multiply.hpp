
#ifndef EXPR_TEMPLATES_MULTIPLY_HPP
#define EXPR_TEMPLATES_MULTIPLY_HPP

#include "pow2.hpp"

#include <cstdlib>

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

#endif //EXPR_TEMPLATES_MULTIPLY_HPP
