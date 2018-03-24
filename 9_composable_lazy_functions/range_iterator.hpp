#ifndef _RANGE_ITERATOR_HPP
#define _RANGE_ITERATOR_HPP

template <typename UnderlyingIterator, typename IncrementFunction, typename DereferenceFunction>
struct range_iterator
{
    using iterator_category = std::input_iterator_tag;
    using value_type        = std::invoke_result_t<DereferenceFunction, UnderlyingIterator>;
    using difference_type   = size_t;
    using pointer           = value_type*;
    using reference         = value_type&;

    UnderlyingIterator  underlyingIter;
    IncrementFunction   increment;
    DereferenceFunction deref;

    constexpr range_iterator(UnderlyingIterator  underlyingIterator,
                             IncrementFunction   increment,
                             DereferenceFunction deref)
        : underlyingIter{underlyingIterator}, increment{increment}, deref{deref} {}

    constexpr void operator++() { increment(underlyingIter); }

    constexpr value_type operator*() { return deref(underlyingIter); }

    constexpr bool operator!=(range_iterator<UnderlyingIterator, IncrementFunction, DereferenceFunction> end) const
    {
        return underlyingIter != end.underlyingIter;
    }

    constexpr void terminateIteration() {
        underlyingIter.terminateIteration();
    }
};

#endif //_RANGE_ITERATOR_HPP
