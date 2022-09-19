#pragma once
// #include <iostream>
#include <cstdint>
#include <vector>

// using Toy = std::uint32_t;
struct Toy {
  std::uint32_t category;
  std::uint32_t interestCount;
};
using ToyList = std::vector<Toy*>;
using Children = std::vector<ToyList>;

struct Category {
  std::uint32_t limit;
  ToyList toysOfCategory;
};
// Category
using Categories = std::vector<std::uint32_t>;  // Category>;