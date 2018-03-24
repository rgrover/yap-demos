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
    auto result1 = square(value);
    auto result2 = twice(result1);
    auto result3 = addOne(result2);

    return result3;
}
