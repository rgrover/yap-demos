#include <functional>

unsigned square(unsigned x) { return x * x; }
unsigned times2(unsigned x) { return 2 * x; }
unsigned plus1(unsigned x) { return x + 1; }

unsigned int value = 1;

int main()
{
    std::function<unsigned(unsigned)> accumulation;
    auto lazy1 = [](unsigned x) {
        return square(x);
    };
    accumulation = lazy1;

    auto lazy2 = [lazy1](unsigned x) {
        return times2(lazy1(x));
    };
    accumulation = lazy2;

    auto lazy3 = [lazy2](unsigned x) {
        return plus1(lazy2(x));
    };
    accumulation = lazy3;

    return accumulation(value);

//    std::function<unsigned(unsigned)> accumulation;
//    accumulation = [](unsigned x) {
//        return square(x);
//    };
//
//    accumulation = [accumulation](unsigned x) {
//        return twice(accumulation(x));
//    };
//
//    accumulation = [accumulation](unsigned x) {
//        return plus1(accumulation(x));
//    };
//
//    return accumulation(value);
}

// my hope is to make a case that lazy accumulation is effective, at least in some cases
