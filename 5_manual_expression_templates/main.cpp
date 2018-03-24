#include <array>

std::array<int, 5> a{{1, 2, 3, 4, 5}};

template <typename Sequence>
struct sequence
{
    constexpr explicit sequence(Sequence const& seq) : seq{seq} {};

    auto operator()(size_t index) const {
        return seq[index];
    }

    Sequence const& seq;
};
template <typename Sequence>
sequence(Sequence) -> sequence<Sequence>;

int main()
{
    auto seq = sequence{a};
    auto e = 2 * (seq ^ 2) + 1;

    return 0;
}
