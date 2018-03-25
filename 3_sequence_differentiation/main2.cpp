#include "fixed_sequence.hpp"
#include <array>

std::array<int, 5> data{{1, 3, 3, 4, 5}};

template <typename Function>
struct differentiator
{
    constexpr explicit differentiator(Function const& f) : f{f} {};

    auto operator()(size_t index) const {
        return f(index + 1) - f(index);
    }

    Function const& f;
};
template <typename F>
differentiator(differentiator<F>) -> differentiator<differentiator<F>>;

int main() {
    fixed_sequence s{data};
    differentiator firstDerivative{s};
    differentiator secondDerivative{firstDerivative};
//    differentiator thirdDerivative{secondDerivative};

    return secondDerivative(0);
//    return thirdDerivative(0);
}
