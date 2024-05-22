#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "header.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

void doItLikeCPP() {
    std::cout << "Printed by C++, called from C" << "\n";
}

    TEST_CASE("shuffle-the-array") {
    SUBCASE("example1") {
        std::vector<int> x{ 0, 1, 8, 13, 5, 2, 3 };
        x[0] = 21;
        x.push_back(1);
        std::sort(x.begin(), x.end());
        std::cout << "Printing " << x.size() << " Fibonacci numbers.\n";
        for (auto number : x) {
        std::cout << number << std::endl;
        }
        CHECK_EQ(x.size(), 8);
        CHECK_EQ(x[0], 1);
        CHECK_EQ(x[1], 1);
        CHECK_EQ(x[2], 2);
        CHECK_EQ(x[3], 3);
        CHECK_EQ(x[4], 5);
        CHECK_EQ(x[5], 8);
        CHECK_EQ(x[6], 13);
        CHECK_EQ(x[7], 21);
  }
}