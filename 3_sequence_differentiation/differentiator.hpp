#ifndef _DIFFERENTIATOR_HPP
#define _DIFFERENTIATOR_HPP

#include <cstdlib>

template <typename Function>
struct differentiator
{
    constexpr explicit differentiator(Function const& f) : f{f} {};

    constexpr auto operator()(size_t index) const
    {
        return f(index + 1) - f(index);
    }

    Function const& f;
};
template <typename Func>
differentiator(Func) -> differentiator<Func>;

#endif //_DIFFERENTIATOR_HPP
