#include <iostream>
#include <array>

struct Sequence {
    int index;
    std::size_t length;
    constexpr int next(int x) {return x + 1;}
    constexpr bool isPart(int x, int y) {return y == next(x);}
};
// Returns index to start of longest increasing seq
template<typename T, std::size_t SIZE>
int longest(std::array<T, SIZE>& input) {
    Sequence longest{0, SIZE};
    Sequence current{0, SIZE};

    int previous = input.front();
    for(auto from = input.begin(); from < input.end() ; ++from) {
        for(auto to = input.begin() + 1; to < input.end() ; ++to) {
            if(*from == *to) {
                current.index = from - input.begin();
                current.length = to - from + 1;
            }
            else
                break;
        }
    }

    return SIZE;
}

template<typename T, std::size_t SIZE>
auto sequence(std::array<T, SIZE>& input, long startIndex) {
    int startValue = input[startIndex];
    auto index = input.begin() + startIndex;
    for(; index < input.end(); ++index) {
        if(*index != startValue) {
            break;;
        }
    }
    return std::pair{startIndex, (index - input.begin())};
}

template<typename T, std::size_t SIZE>
auto findSeqEnd(std::array<T, SIZE>& input, int startIndex, int (*step)(int stepSize)) {

    return 0;
}

int main() {
    // deduction guide for array creation (since C++17)
    std::array nums{1,2,3,1,2,3,4,1,2,3,4,5,1,2,3,1,1,1};
    auto [x, y] = sequence(nums, 0);
    std::cout << "x: " << x << " y: " << y << std::endl;
    auto [x1, y1] = sequence(nums, 15);
    std::cout << "x: " << x1 << " y: " << y1 << std::endl;
    // std::cout << longest(nums) << std::endl;
}