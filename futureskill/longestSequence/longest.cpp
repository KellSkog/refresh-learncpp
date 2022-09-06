#include <iostream>
#include <vector>

constexpr int delta = -1; // difference between neighbors

/* returns the position after last in sequence */
template<typename T>
auto findSeqEnd(T start, T end) {
    auto endsAt = start + 1;
    for(; endsAt < end; ++endsAt) {
        if(*endsAt != (*(endsAt - 1) + delta)) {
            break;
        }
    }
    return endsAt;
}
template<typename T>
auto findLongestSeq(T &nums) {
    auto length = 0;
    auto longestStart = nums.begin();
    auto longestLen = 0;
    for(auto from = nums.begin(); from < nums.end(); ) {
        auto end = findSeqEnd(from, nums.end());
        length = end - from;
        if(length > longestLen) {
            longestLen = length;
            longestStart = from;
        }
        from = end;
    }
    return std::pair{longestStart, longestLen};
}

int main() {
    // std::vector nums{1,2,3,1,2,3,4,1,2,3,4,5,1,2,3,1,1,1};
    std::vector nums{1,2,3,4,5,6,10,9};
    auto [start, length] = findLongestSeq(nums);

    std::cout << "From: " << (start - nums.begin()) << " length: " << length << std::endl;
}