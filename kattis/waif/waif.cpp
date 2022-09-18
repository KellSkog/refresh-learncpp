/* https://open.kattis.com/problems/waif
 * Goal: Display the maximum number of children
 * that can be satisfied with a toy that they like,
 * provided that each toy can be used by at most one child.
 */
#include "waif.hpp"

#include <algorithm>
#include <iostream>
#include <set>
// #include <typeinfo>

/*
 * Toys in category 0 has no category, any number can be played with
 *
 */

template <typename T, typename S>
[[maybe_unused]] void showContent(T &children, S &categories) {
  std::cout << "Wanted toys:\n";
  for (const auto &x : children) {
    for (const auto &y : x) {
      std::cout << y << ", ";
    }
    std::cout << "\n";
  }
  std::cout << "Categorized toys:\n";
  for (const auto &x : categories) {
    for (const auto &y : x.toysOfCategory) {
      std::cout << y << ", ";
    }
    std::cout << " Limit " << x.limit << "\n";
  }
}
int main() {
  std::uint32_t childCount;
  std::uint32_t toyCount;
  std::uint32_t categoryCount;
  std::uint32_t satisfiedCount = 0;

  std::cin >> childCount >> toyCount >> categoryCount;

  /* First fill uncategorized set with all toys
   * Build vector of children with set of prefered toys
   * Build vector of categories with set of toys, take from uncategorized set
   * From set of uncathegorized toys give toy to children from shortest prefered list to longest
   * Update satisfied count and remove child that has received toy
   *
   * For children from shortest prefered list to longest
   * Give a toy from any category with limit >0 that the child is satisfied with
   * Update satisfied count, remove toy from category and subtract from limit, skip to next child
   */

  // First fill uncategorized set with all toys
  //   std::vector<std::uint32_t> uncategorized(toyCount);
  std::set<std::uint32_t> uncategorized;
  for (std::uint32_t toy = 1; toy <= toyCount; ++toy) {
    uncategorized.insert(toy);
  }

  Children children(childCount);
  for (std::uint32_t child = 0; child < childCount; ++child) {
    std::uint32_t toys;
    std::cin >> toys;
    children[child] = ToyList(toys);
    for (std::uint32_t i = 0; i < toys; ++i) {
      std::cin >> children[child][i];
    }
  }

  Categories categories(categoryCount);
  for (std::uint32_t category = 0; category < categoryCount; ++category) {
    std::uint32_t toys;
    std::cin >> toys;

    categories[category] = Category{0, ToyList(toys)};
    for (std::uint32_t i = 0; i < toys; ++i) {
      std::uint32_t toy;
      std::cin >> toy;
      categories[category].toysOfCategory[i] = toy;  // Move the toy from uncathegorized
      auto ptr = uncategorized.find(toy);
      uncategorized.erase(ptr);
    }
    std::cin >> categories[category].limit;
  }
  // Sort children from shortest to longest toylist
  std::sort(children.begin(), children.end(),
            [](ToyList a, ToyList b) { return a.size() < b.size(); });
  // Sort categories from shortest to longest toylist
  std::sort(categories.begin(), categories.end(), [](Category a, Category b) {
    return a.toysOfCategory.size() < b.toysOfCategory.size();
  });
  // showContent(children, categories);

  // From set of uncathegorized toys give toy to children
  for (auto childIterator = children.begin(); childIterator < children.end();
       ++childIterator) {  // Iterate over children
    for (auto prefeferdToyIterator = (*childIterator).begin();
         prefeferdToyIterator != (*childIterator).end(); ++prefeferdToyIterator) {
      if (auto ptr = uncategorized.find(*prefeferdToyIterator); ptr != uncategorized.end()) {
        satisfiedCount++;
        uncategorized.erase(ptr);
        // The child needs no furtherprocessing
        goto nextChild;
      } else {
        for (auto category = categories.begin(); category < categories.end(); ++category) {
          if (auto toyInCategory = std::find(category->toysOfCategory.begin(),
                                             category->toysOfCategory.end(), *prefeferdToyIterator);
              toyInCategory != category->toysOfCategory.end() && category->limit > 0) {
            satisfiedCount++;
            category->toysOfCategory.erase(toyInCategory);
            --category->limit;
            // The child needs np furtherprocessing
            goto nextChild;
          }
        }
      }  // else
    }
  nextChild:;
  }

  std::cout << satisfiedCount << std::endl;
  // showContent(children, categories);
}

/* https://linuxhint.com/vector-of-vectors-cpp/ */
[[maybe_unused]] void vectors() {
  using namespace std;
  using Vchar = vector<char>;
  using size_type = std::vector<Vchar>::size_type;
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

  for (size_type i = 0; i < twoDV.size(); i++) {
    for (size_type j = 0; j < twoDV[i].size(); j++) {
      cout << twoDV[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}