#include <iostream>

#include "shuffle-the-array.hpp"
// nums.size() == 2n
vector<int> Solution::shuffle(vector<int>& nums, int n) {
    // Need a vector to return
    vector<int> vec{};
    // Fill it alternatingly fron nums[i] and nums[i + n]
    for(int i = 0; i < n; ++i) {
        cout << nums[i] << ", " << nums[i + n] << "\n";
        vec.push_back(nums[i]);
        vec.push_back(nums[i + n]);
    }
    return vec; // Return by value =:-o
}