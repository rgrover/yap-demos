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
    nth_differentiator(F func) : func{func} {};

    auto operator()(size_t index) {
        auto nMinusOne = make_nth_differentiator<N-1>(func);
        return nMinusOne(index + 1) - nMinusOne(index);
    }

    F func;
};

template <typename F>
struct nth_differentiator<0, F>
{
    nth_differentiator(F func) : func{func} {};

    auto operator()(size_t index) {
        return func(index);
    }

    F func;
};

int main()
{
    auto nth = make_nth_differentiator<0>(discrete_sequence{a});

    return nth(0);
}
