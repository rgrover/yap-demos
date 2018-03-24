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

    auto operator()(size_t index) const {
        return f(index + 1) - f(index);
    }

    Function const& f;
};
template <typename Func>
differentiator(Func) -> differentiator<Func>;

template <size_t N, typename Func>
struct nth_differentiator;

template <size_t N, typename Func>
constexpr auto make_nth_differentiator(Func f)
{
    return nth_differentiator<N, Func>{f};
};

template <size_t N, typename PartialDifferentiator>
struct nth_differentiator
{
    constexpr explicit nth_differentiator(PartialDifferentiator const& f) : f{f} {};

    constexpr auto operator()(size_t index) const
    {
        auto nMinusOne = make_nth_differentiator<N-1>(f);
        return nMinusOne(index + 1) - nMinusOne(index);
    }

    PartialDifferentiator f;
};

template <typename UnderlyingFunction>
struct nth_differentiator<0, UnderlyingFunction>
{
    constexpr explicit nth_differentiator(UnderlyingFunction const& f) : f{f} {};

    constexpr auto operator()(size_t index) const
    {
        return f(index);
    }

    UnderlyingFunction f;
};

int main()
{
    auto nth = make_nth_differentiator<3>(sequence{a});

    return nth(0);
}
