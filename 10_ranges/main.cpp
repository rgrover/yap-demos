#include "range.hpp"
#include "scalars.hpp"
#include "map.hpp"
#include "filter.hpp"
#include "take.hpp"
#include "callable.hpp"
#include "fold.hpp"
#include "xforms.hpp"
#include "drop.hpp"

#include <vector>
#include <iostream>

using namespace boost::yap;

unsigned squared(unsigned x) { return x * x; }
unsigned subtract1(unsigned x) {return x - 1;}
unsigned add(unsigned x, unsigned v) {return x + v;}
unsigned multiply(unsigned x, unsigned v) {return x * v;}
bool odd(unsigned x) { return (x % 2) == 1; }
bool even(unsigned x) { return (x % 2) == 0;}

int main()
{
//    auto e =
        foldl(multiply, 1)
             <<= drop(1)
             <<= take(4)
             <<= filter([](unsigned x) { return (x % 5) == 0; })
             <<= map(apply(subtract1) *= apply(squared))
             <<= filter(odd)
             <<= scalars<unsigned>{};

//    auto t = boost::yap::transform(e, xforms{});
//    std::cout << t << std::endl;

//    std::vector<int> v = boost::yap::transform(e, xforms{});
//    for (auto value : v) {
//        std::cout << value << std::endl;
//    }
}
