#include <iostream>

struct Foo {
    static int num;
    int sum;
    static void foo();
    void fooo();
};
namespace Poo {
    int num;
}

void Foo::foo() {
    std::cout << "Foofoo: " << Poo::num << "\n";
}

void Foo::fooo() {
    std::cout << "Foofooo: " << sum << "\n";
}

int main() {
    // Foo::num = 42;
    Poo::num = 4;
    Foo::foo();

    Foo foe;
    foe.sum = 17;
    foe.fooo();
}