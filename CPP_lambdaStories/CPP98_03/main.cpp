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
    
    std::cout << std98::main() << "\n";
    std::cout << std11::stdBind() << "\n";
}