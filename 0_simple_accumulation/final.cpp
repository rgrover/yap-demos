#include <functional>

unsigned square(unsigned x) {
    return x * x;
}

unsigned twice(unsigned x) {
    return 2 * x;
}

unsigned addOne(unsigned x) {
    return x + 1;
}

unsigned int value = 1;

int main()
{
    std::function<unsigned(unsigned)> accumulation;

    auto task1 = [](unsigned x) {
        return square(x);
    };
    accumulation = task1;

    auto task2 = [task1](unsigned x) {
        return twice(task1(x));
    };
    accumulation = task2;

    auto task3 = [task2](unsigned x) {
        return addOne(task2(x));
    };
    accumulation = task3;

    return accumulation(value);
}
