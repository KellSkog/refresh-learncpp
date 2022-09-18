#pragma once
// #include <iostream>
#include <cstdint>
#include <vector>

using Toy = std::uint32_t;
using ToyList = std::vector<Toy>;
using Children = std::vector<ToyList>;

struct Category {
  std::uint32_t limit;
  ToyList toysOfCategory;
};
using Categories = std::vector<Category>;