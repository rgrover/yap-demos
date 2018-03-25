// recall our first example around vectors?
//
//    std::array<unsigned, 100> values;
//
//    template <typename Sequence>
//    void square(Sequence& s) { /* having to take values by reference for the sake of performance */
//        ...
//    }
//
//    int main()
//    {
//        square(values);

// let's create a domain-specific vocabulary for it

#include "discrete_sequence.hpp"
#include <array>

std::array<int, 5> a{{1, 2, 3, 4, 5}};

int main()
{
    auto seq = discrete_sequence{a};
    auto e = 2 * (seq ^ 2) + 1; /* we intend to write a lazy expression for a transformed sequence */

    return 0;
}
