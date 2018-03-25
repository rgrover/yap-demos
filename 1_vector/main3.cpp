#include <array>

/*const */std::array<unsigned, 100> values /*= {{1}}*/;

unsigned square(unsigned x) { return x * x; }
unsigned times2(unsigned x) { return 2 * x; }
unsigned plus1(unsigned x) { return x + 1; }

int main()
{
    auto lazy1 = [](unsigned x) {
        return x * x;
    };

    auto lazy2 = [lazy1](unsigned x) {
        return 2 * (lazy1(x));
    };

    auto lazy3 = [lazy2](unsigned x) {
        return lazy2(x) + 1;
    };

    return lazy3(values[0]); /* note: passing by value. */

//    std::array<unsigned, 100> result;
//    for (auto i = 0; i < values.size(); ++i) {
//        result[i] = lazy3(values[i]);
//    }
//    result[0] = lazy3(values[0]);
//    return result[0];
}
