#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "shuffle-the-array.hpp"

TEST_CASE("shuffle-the-array") {
    Solution solution;
  SUBCASE("example1") {
    vector<int> vec{2,5,1,3,4,7};
    CHECK_EQ(vec.size(), 6);
    vector<int> vector = solution.shuffle(vec, vec.size()/2);
    CHECK_EQ(vector[0], vec[0]);
    CHECK_EQ(vector[1], vec[3]);
    CHECK_EQ(vector[2], vec[1]);
    CHECK_EQ(vector[3], vec[4]);
    CHECK_EQ(vector[4], vec[2]);
    CHECK_EQ(vector[5], vec[5]);
  }
}