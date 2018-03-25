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

int main() {
    fixed_sequence s{data};
    differentiator firstDerivative{s};
    differentiator secondDerivative{firstDerivative}; // the danger of invoking the copy constructor

    return firstDerivative(0);
//    return secondDerivative(0);
}
