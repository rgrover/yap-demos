#ifndef _SCALARS_HPP
#define _SCALARS_HPP

#include "range.hpp"
#include "scalar_iterator.hpp"

#include <boost/yap/algorithm.hpp>

template <typename T>
struct scalars
{
    using value_type = T;
    using iterator_type = scalar_iterator<T>;

    constexpr static boost::yap::expr_kind kind = boost::yap::expr_kind::terminal;

    using tuple_element_type = range<iterator_type>;
    boost::hana::tuple<tuple_element_type> elements;

    // constructors
    constexpr scalars() : elements{{{T{}, T{1}}, {T{}, T{}, true}}} {}
    constexpr scalars(T start) : elements{{{start, T{1}}, {start, T{}, true}}} {}
    constexpr scalars(T start, T end) : elements{{{start, T{1}}, {end, T{}}}} {}
    constexpr scalars(T start, T step, T end) :elements{{{start, step}, {end, T{}}}} {}
};

#endif //_SCALARS_HPP
