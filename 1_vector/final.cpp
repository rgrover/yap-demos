#include <array>
#include <functional>

std::array<unsigned, 100> values;

template <typename Sequence>
void square(Sequence& s) {
    for (auto& value : s) {
        value = value * value;
    }
}

template <typename Sequence>
void twice(Sequence& s) {
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

int main()
{
#if 1
    square(values);
    twice(values);
    addOne(values);

    return values[0];
#else
    std::function<unsigned(unsigned)> accumulation;

    auto task1 = [](unsigned x) {
        return x * x;
    };
    accumulation = task1;

    auto task2 = [task1](unsigned x) {
        return 2 * (task1(x));
    };
    accumulation = task2;

    auto task3 = [task2](unsigned x) {
        return task2(x) + 1;
    };
    accumulation = task3;

    for (auto &value : values) {
        value = accumulation(value);
    }
    return accumulation(values[0]);
#endif
}
