unsigned square(unsigned x) { return x * x; }
unsigned times2(unsigned x) { return 2 * x; }
unsigned addOne(unsigned x) { return x + 1; }

unsigned int x = 1;

int main()
{
    return addOne(times2(square(x))); /* would perhaps appeal to a mathematician */

//    auto lazy1 = [](unsigned x) {
//        return square(x);
//    };
//    auto lazy2 = [lazy1](unsigned x) {
//        return twice(lazy1(x));
//    };
//    auto lazy3 = [lazy2](unsigned x) {
//        return addOne(lazy2(x));
//    };
//
//    /* and sometime later*/
//    return lazy3(x); /* also computes 2x² + 1 upon demand; but may appear circuitous */
}

/* or you could type-erase the lambdas using std::function<> for aesthetics */
