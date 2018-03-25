#include <array>

std::array<unsigned, 100> values;

template <typename Xform, typename Sequence>
void xformUsing(Xform f, Sequence& s) {
    for (auto& value : s) {
        value = f(value);
    }
}

unsigned square(unsigned x) { return x * x; }
unsigned times2(unsigned x) { return 2 * x; }
unsigned plus1(unsigned x) { return x + 1; }

int main()
{
    xformUsing(square, values);
    xformUsing(times2, values);
    xformUsing(plus1, values);

    return values[0];
// still nothing, but then we can bring in our lazy accumulation
}
