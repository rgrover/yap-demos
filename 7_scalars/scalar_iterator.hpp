#ifndef _SCALAR_ITERATOR_HPP
#define _SCALAR_ITERATOR_HPP

#include <iterator>

template <typename T>
struct scalar_iterator
{
    using iterator_category = std::input_iterator_tag;
    using value_type        = T;
    using difference_type   = size_t;
    using pointer           = T*;
    using reference         = T&;

    T value;
    T step;
    bool isLogicalSentinel{false}; /* logical end for infinite ranges */

    constexpr void operator++() { value += step; }

    constexpr T operator*() const { return value; }

    constexpr void terminateIteration() {
        isLogicalSentinel = true;
    }
};

template <typename T>
constexpr bool operator!=(scalar_iterator<T> a, scalar_iterator<T> b)
{
    if (a.isLogicalSentinel) {
        return false;
    }
    if (b.isLogicalSentinel) {
        return true;
    }

    return a.value < b.value;
}

#endif // _SCALAR_ITERATOR_HPP
