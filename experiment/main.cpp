#include <iostream>
#include "algo.hpp"

int main() {
    int x = 42;
    // int &y = x;
    int &z = getRef(&x);
    std::cout << "Z: " << z << "\n";
}