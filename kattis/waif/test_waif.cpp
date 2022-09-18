#include <fstream>
#include <iostream>

#include "waif.hpp"

int main() {
  std::cout << "Everything is hunky dory!" << std::endl;
  // open file for reading
  std::string filename = "waif/input1";
  std::ifstream istrm(filename);
  std::istream &input = istrm;
  if (!istrm.is_open()) {
    std::cout << "failed to open " << filename << '\n';
    return -1;
  }

  std::uint32_t childCount;
  std::uint32_t toyCount;
  std::uint32_t categoryCount;

  input >> childCount >> toyCount >> categoryCount;
  std::cout << "Chld: " << childCount << ", ToycCnt: " << toyCount
            << ", CategoryCnt: " << categoryCount << std::endl;
  Children children(childCount);
  for (std::uint32_t child = 0; child < childCount; ++child) {
    std::uint32_t toys;
    input >> toys;
    children[child] = ToyList(toys);
    for (std::uint32_t i = 0; i < toys; ++i) {
      input >> children[child][i];
    }
  }

  Categories categories(categoryCount);
  for (std::uint32_t category = 0; category < categoryCount; ++category) {
    std::uint32_t toys;
    input >> toys;

    categories[category] = Category{0, ToyList(toys)};
    for (std::uint32_t i = 0; i < toys; ++i) {
      input >> categories[category].toysOfCategory[i];
    }
    input >> categories[category].limit;
  }

  istrm.close();
}