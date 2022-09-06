#include <iostream>
#include <string>

struct Test {
    std::string reverse(std::string input) {
        std::string out;
        // end points to next after last!
        for(auto i = input.end() - 1; i >= input.begin(); --i) {
            out.push_back(*i);
        }
        return out;
    }
};

int main() {
    Test t;
    std::string rev = t.reverse("Hello bob!");
    std::cout << rev << std::endl;
}