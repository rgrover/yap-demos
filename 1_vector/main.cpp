#include <array>

std::array<unsigned, 100> values;

template <typename Sequence>
void square(Sequence& s) { /* having to take values by reference for the sake of performance */
    for (auto& value : s) {
        value = value * value;
    }
}

template <typename Sequence>
void times2(Sequence& s) {
    for (auto& value : s) {
        value = 2 * value;
    }
}

template <typename Sequence>
void addOne(Sequence& s) {
    for (auto& value : s) {
        value += 1;
    }
}

// lots of code duplication above..

int main()
{
    square(values);
    times2(values);
    addOne(values);

    return values[0];
}

// we can do something to bring together common code
