#ifndef _SCALAR_ITERATOR_HPP
#define _SCALAR_ITERATOR_HPP

#include <iterator>
#include <optional>

template <typename T>
struct scalar_iterator
{
    using iterator_category = std::input_iterator_tag;
    using value_type        = T;
    using difference_type   = size_t;
    using pointer           = T*;
    using reference         = T&;

    scalar_iterator(T value, T step) : gen{generator{value, step}} {}
    scalar_iterator() : gen{} {}

    struct generator {
        T    value;
        T    step;
    };
    std::optional<generator> gen;

    constexpr void operator++() { gen->value += gen->step; }
    constexpr T operator*() const { return gen->value; }

    constexpr void terminateIteration() {
        gen.reset();
    }
    constexpr bool isLogicalSentinel() const { return !static_cast<bool>(gen); }
};

template <typename T>
constexpr bool operator!=(scalar_iterator<T> a, scalar_iterator<T> b)
{
    if (a.isLogicalSentinel()) {
        return false;
    }
    if (b.isLogicalSentinel()) {
        return true;
    }

    return a.gen->value < b.gen->value;
}

#endif // _SCALAR_ITERATOR_HPP
