#ifndef _DIFFERENTIATOR_HPP
#define _DIFFERENTIATOR_HPP

template <typename Function>
struct differentiator
{
    constexpr explicit differentiator(Function f, double delta = 0.001) :
        f{f}, delta{delta} {};

    auto operator()(double x) const
    {
        return (f(x + delta) - f(x)) / delta;
    }

    Function     f;
    const double delta = 0.001;
};
template <typename UnderlyingPartial>
differentiator(UnderlyingPartial) -> differentiator<UnderlyingPartial>;

#endif //_DIFFERENTIATOR_HPP
