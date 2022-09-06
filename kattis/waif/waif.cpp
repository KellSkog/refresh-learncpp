/* https://open.kattis.com/problems/waif
 * Goal: Display the maximum number of children 
 * that can be satisfied with a toy that they like,
 * provided that each toy can be used by at most one child.
 */
#include <iostream>
#include <array>

/*
 * Toys in category 0 has no category, any number can be played with
 * 
*/
struct Toy {
    unsigned toyId;
    unsigned toyCategory;
};
struct Child {
    std::array<Toy, 100> child;
};

int main() {
    std::cout << "waif!\n";
}