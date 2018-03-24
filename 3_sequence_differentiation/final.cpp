#include <array>

std::array<int, 5> data{{1, 3, 3, 4, 5}};

template <typename Sequence>
struct fixed_sequence
{
    constexpr explicit fixed_sequence(Sequence const& seq) : seq{seq} {};

    auto operator()(size_t index) const {
        return seq[index];
    }

    Sequence const& seq;
};

template <typename Function>
struct differentiator
{
    constexpr explicit differentiator(Function const& f) : f{f} {};

    auto operator()(size_t index) const {
        return f(index + 1) - f(index);
    }

    Function const& f;
};
template <typename Another>
differentiator(differentiator<Another>) -> differentiator<differentiator<Another>>;

int main() {
    fixed_sequence s{data};
    differentiator firstDerivative{s};
    differentiator secondDerivative{firstDerivative};
    differentiator thirdDerivative{secondDerivative};

    return thirdDerivative(0);
}
