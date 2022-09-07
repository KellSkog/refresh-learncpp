#include <iostream>
#include <vector>

/* returns the position after last in sequence
 * @param start iterator where search begins
 * @param end iterator to end
 * @param func is the sequence generator
 * @returns iterator to next seq */
template <typename T>
auto findSeqEnd(T start, T end, int (*func)(int x))
{
    auto endsAt = start + 1;
    for (; endsAt < end; ++endsAt)
    {
        if (*endsAt != func(*(endsAt - 1)))
        {
            break;
        }
    }
    return endsAt;
}
template <typename T>
auto findLongestSeq(T &nums)
{
    auto length = 0;
    auto longestStart = nums.begin();
    auto longestLen = 0;
    for (auto from = nums.begin(); from < nums.end();)
    {
        auto end = findSeqEnd(from, nums.end(), [](int x) -> int
                              { return x - 1; });
        length = end - from;
        if (length > longestLen)
        {
            longestLen = length;
            longestStart = from;
        }
        from = end;
    }
    return std::pair{longestStart, longestLen};
}

int main()
{
    // std::vector nums{1,2,3,1,2,3,4,1,2,3,4,5,1,2,3,1,1,1};
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 10, 9};
    auto [start, length] = findLongestSeq(nums);

    std::cout << "From: " << (start - nums.begin()) << " length: " << length << std::endl;
}