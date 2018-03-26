
/* I propose to create the following domain-specific language. */

main()
{
    auto e =    take(4_c)
            <<= map(apply(plus1) *= apply(times2) *= apply(squared))
            <<= filter(odd)
            <<= scalars<unsigned>{0, 1, 100};

//    auto result = transform(e, xforms{});

//    std::vector<int> v = result;
//    for (auto value : v) {
//        std::cout << value << std::endl;
//    }
}
