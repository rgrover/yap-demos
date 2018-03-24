unsigned square(unsigned x) {
    return x * x;
}

unsigned twice(unsigned x) {
    return 2 * x;
}

unsigned addOne(unsigned x) {
    return x + 1;
}

const unsigned int value = 1;

int main()
{
    auto task1 = [](unsigned x) {
        return square(x);
    };
    auto task2 = [task1](unsigned x) {
        return twice(task1(x));
    };
    auto task3 = [task2](unsigned x) {
        return addOne(task2(x));
    };

    return task3(value);
}
