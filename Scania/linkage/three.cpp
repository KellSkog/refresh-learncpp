/* Without extern C:
 * three.cpp:(.text+0xe): undefined reference to `first(int)'
 * /usr/bin/ld: three.cpp:(.text+0x15): undefined reference to `second(int)'*/
extern "C" {
#include "one.h"
// #include "two.h"
int second(int beta);
}
#include <iostream>
int main() { std::cout << second(first(4)) << "\n"; }

int third(int gamma) { return 5 * gamma; }