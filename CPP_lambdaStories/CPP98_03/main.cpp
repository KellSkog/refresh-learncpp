#include <algorithm>
#include <iostream>
#include <vector>

#include "lambdas.hpp"



int main() {
    std98::doIt();
    std11::doIt();

    std98::usePrintFunc();
    std98::usePrinterEx();
    std11::usePrinterEx();
    std11::useLocalFunctionObject();
    
    std::cout << std98::bind2nd() << "\n";
    std::cout << std11::stdBind() << "\n";

    // 1. the simplest lambda:
    []{};
    int x = 1;
    [&x]() mutable {++x;}();
    std::cout << "Lambda with side effect: " << x << "\n";
}