#include <algorithm>
#include <functional>
#include <iostream>
#include <typeinfo>
#include <vector>

#include "lambdas.hpp"

template<typename L>
    std::string lambda_Type(L&& lambda) {
        return typeid(lambda).name();
    }
void someFunction(){}
void autoAndFunction() {
    auto myLambda = []->int{return 42;};
    std::function<void()> otherFunc = []{};
    std::function<void()> anotherFunc = someFunction;
    std::cout << "Size of myLambda: " << sizeof(myLambda)  << "\n";
    // std::cout << "Size of someFunction: " << sizeof(someFunction)  << "\n"; //error: ISO C++ forbids applying ‘sizeof’ to an expression of function type [-fpermissive]
    std::cout << "Size of anotherFunc: " << sizeof(anotherFunc)  << "\n";
    std::cout << "Size of otherFunc: " << sizeof(otherFunc)  << "\n";
}

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

    std::cout << "Typename of [](int x) noexcept { return x * 2; }" << lambda_Type([](int x) noexcept { return x * 2; }) << "\n";
    std::cout << "Typename of [](int x) noexcept { return x * 2; }" << lambda_Type([](int x) noexcept { return x * 2; }) << "\n";
    autoAndFunction();
}