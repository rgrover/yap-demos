#include "discrete_sequence.hpp"
#include "differentiator.hpp"
#include <array>

std::array<int, 5> a{{1, 2, 3, 4, 5}};

template <size_t N, typename F>
struct nth_differentiator;

template <size_t N, typename Func>
constexpr auto make_nth_differentiator(Func f) {
    return nth_differentiator<N, Func>{f};
}

template <size_t N, typename F>
struct nth_differentiator
{
    //
};

int main()
{
    auto nth = make_nth_differentiator<0>(discrete_sequence{a});

    return nth(0);
}
