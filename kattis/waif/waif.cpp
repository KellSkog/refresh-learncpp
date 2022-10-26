/* https://open.kattis.com/problems/waif
 * Goal: Display the maximum number of children
 * that can be satisfied with a toy that they like,
 * provided that each toy can be used by at most one child.
 */

#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>

/*
 * Toys in category 0 has no category, any number can be played with
 *
 */

struct Toy;
using ToyList = std::vector<Toy *>;
struct Category {
  std::uint32_t limit;
  ToyList toysOfCategory;
  std::uint32_t interest;
};
using Categories = std::vector<Category>;

struct Toy {
  bool isTaken;
  Category *category;
  std::uint32_t interestCount;
};
using Children = std::vector<ToyList>;

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
bool isAvailable(Toy *toy) {
  if (toy->category)
    return ((!toy->isTaken) && (toy->category->limit > 0));
  else {  // Uncategorized
    return (!toy->isTaken);
  }
}
int main() {
  std::uint32_t childCount;
  std::uint32_t toyCount;
  std::uint32_t categoryCount;
  std::uint32_t satisfiedCount = 0;

  std::cin >> childCount >> toyCount >> categoryCount;

  /* First fill setOfToys set with all toys
   * Build vector of children with set of prefered toys
   * Build vector of categories with set of toys, take from setOfToys set
   * From set of uncathegorized toys give toy to children from shortest prefered list to longest
   * Update satisfied count and remove child that has received toy
   *
   * For children from shortest prefered list to longest
   * Give a toy from any category with limit >0 that the child is satisfied with
   * Update satisfied count, remove toy from category and subtract from limit, skip to next child
   */

  // First fill setOfToys set with all toys
  std::array<Toy, 101> setOfToys;
  for (std::uint32_t toy = 1; toy <= toyCount; ++toy) {
    setOfToys[toy] = Toy{false, nullptr, 0};  // Create 101 not given, uncathegorized toys, wanted by no one
  }

  Children children(childCount + 1);  // Each child in children has a vector of pointers to toy
  for (std::uint32_t child = 1; child <= childCount; ++child) {
    std::uint32_t toyCount;
    std::cin >> toyCount;  // No of toys in this childs prefered list
    children[child] = ToyList(toyCount);
    for (std::uint32_t i = 0; i < toyCount; ++i) {
      std::uint32_t toy;
      std::cin >> toy;
      Toy *theToy = &setOfToys[toy];
      children[child][i] = theToy;
      theToy->interestCount++;
    }
  }

  Categories categories(categoryCount + 1);
  for (std::uint32_t category = 1; category <= categoryCount; ++category) {
    std::uint32_t toys;
    std::cin >> toys;

    for (std::uint32_t i = 0; i < toys; ++i) {
      std::uint32_t toy;
      std::cin >> toy;
      categories[category].interest += setOfToys[toy].interestCount;
      setOfToys[toy].category = &categories[category];  // Assign the toy to its category
    }
    std::cin >> categories[category].limit;
  }
  // Sort children from shortest to longest toylist
  std::sort(children.begin(), children.end(), [](ToyList a, ToyList b) { return a.size() < b.size(); });

  for (auto child : children) {  // Sort prefered toys list based on interest
    std::sort(child.begin(), child.end(), [](Toy *a, Toy *b) { return a->interestCount < b->interestCount; });
  }
  for (auto &child : children) {
    for (auto *toy : child) {
      if (isAvailable(toy)) {  // If this prefered toy is available (not taken nor in an exhausted category)
        toy->isTaken = true;
        satisfiedCount++;
        if (toy->category) {
          --toy->category->limit;
        }
      }
    }
  }

  std::cout << satisfiedCount << std::endl;
  // showContent(children, categories);
}