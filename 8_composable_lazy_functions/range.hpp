#ifndef _RANGE_HPP
#define _RANGE_HPP

template <typename Iter>
struct range
{
    using iterator = Iter;

    Iter beginIter;
    Iter endIter;

    range(Iter b, Iter e) : beginIter{b}, endIter{e} {}

    Iter& begin() { return beginIter; }
    Iter& end() { return endIter; }

    Iter const& cbegin() const { return beginIter; }
    Iter const& cend() const { return endIter; }

    template <typename Assignee>
    constexpr operator Assignee() const
    {
        return {cbegin(), cend()};
    }
};

#endif //_RANGE_HPP
