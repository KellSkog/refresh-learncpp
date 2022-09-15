/* https://open.kattis.com/problems/waif
 * Goal: Display the maximum number of children
 * that can be satisfied with a toy that they like,
 * provided that each toy can be used by at most one child.
 */
#include <iostream>
#include <typeinfo>
#include <vector>

/*
 * Toys in category 0 has no category, any number can be played with
 *
 */

using Toy = std::uint32_t;
using ChildToyList = std::vector<Toy>;
using Children = std::vector<ChildToyList>;

struct Category {
  std::uint32_t limit;
  ChildToyList toysOfCategory;
};
using Categories = std::vector<Category>;

int main() {
  std::uint32_t childCount;
  std::uint32_t toyCount;
  std::uint32_t categoryCount;

  std::cin >> childCount >> toyCount >> categoryCount;

  Children children(childCount);
  for (std::uint32_t child = 0; child < childCount; ++child) {
    std::uint32_t toys;
    std::cin >> toys;
    children[child] = ChildToyList(toys);
    for (int i = 0; i < toys; ++i) {
      std::cin >> children[child][i];
    }
  }

  Categories categories(categoryCount);
  for (std::uint32_t category = 0; category < categoryCount; ++category) {
    std::uint32_t toys;
    std::cin >> toys;

    categories[category] = Category{0, ChildToyList(toys)};
    for (int i = 0; i < toys; ++i) {
      std::cin >> categories[category].toysOfCategory[i];
    }
    std::cin >> categories[category].limit;
  }

  for (auto x : children) {
    for (auto y : x) {
      std::cout << y << ", ";
    }
    std::cout << "\n";
  }
  for (auto x : categories) {
    for (auto y : x.toysOfCategory) {
      std::cout << y << ", ";
    }
    std::cout << x.limit << "\n";
  }
}

/* https://linuxhint.com/vector-of-vectors-cpp/ */
[[maybe_unused]] void vectors() {
  using namespace std;
  using Vchar = vector<char>;
  vector<Vchar> twoDV = {{'A', 'B', 'C', 'D', 'E'},  // p
                         {'B', 'C', 'D', 'E', 'A'},  // Will be erased
                         {'C', 'D', 'E', 'A', 'B'},  // Up to q will be erased
                         {'D', 'E', 'A', 'B', 'C'},
                         {'E', 'A', 'B', 'C', 'D'}};

  vector<Vchar>::iterator p = twoDV.begin();
  p++;
  vector<Vchar>::iterator q = twoDV.end();
  q--;
  q--;

  twoDV.erase(p, q);

  for (int i = 0; i < twoDV.size(); i++) {
    for (int j = 0; j < twoDV[i].size(); j++) {
      cout << twoDV[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}