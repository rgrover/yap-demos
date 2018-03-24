unsigned square(unsigned x) { return x * x; }
unsigned times2(unsigned x) { return 2 * x; }
unsigned addOne(unsigned x) { return x + 1; }

const unsigned int x = 1;

int main()
{
    auto result1 = square(x);
    auto result2 = times2(result1);
    auto result3 = addOne(result2);

    return result3; /* contains 2x² + 1 */
}
