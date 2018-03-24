

main()
{
    auto e =    take(4)
            <<= map(apply(subtract1) *= apply(squared))
            <<= filter(odd)
            <<= scalars<unsigned>{0, 1, 100};

//    auto result = transform(e, xforms{});

//    std::vector<int> v = result;
//    for (auto value : v) {
//        std::cout << value << std::endl;
//    }
}
