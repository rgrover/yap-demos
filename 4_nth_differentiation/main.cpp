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

template <typename Function>
struct differentiator
{
    constexpr explicit differentiator(Function const& f) : f{f} {};

    constexpr auto operator()(size_t index) const
    {
        return f(index + 1) - f(index);
    }

    Function const& f;
};
template <typename Func>
differentiator(Func) -> differentiator<Func>;

template <size_t N, typename Func>
constexpr auto make_nth_differentiator(Func f)
{
};

int main()
{
    auto nth = make_nth_differentiator<0>(sequence{a});

    return nth(0);
}
