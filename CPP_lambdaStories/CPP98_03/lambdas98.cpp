#include <algorithm>
#include <iostream>
#include <vector>

#include "lambdas.hpp"

void std98::doIt() {
    std::cout << "Doing it C++98 style\n";
}

void PrintFunc(int x) {
    std::cout << x << "\n";
}

namespace detail {
class Printer {
    public:
    void operator()(int x) const {
    std::cout << x << '\n';
    }
};
class PrinterEx {
    public:
        PrinterEx() : _CallCnt(0) { }
        void operator()(int x) {
            std::cout << x << '\n';
            ++_CallCnt;
        }
    int _CallCnt;
};
}

void std98::usePrintFunc() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    std::for_each(vec.begin(), vec.end(), PrintFunc);

    std::for_each(vec.begin(), vec.end(), detail::Printer());

    detail::Printer printer;
    printer(42); // calls operator()
    printer.operator()(1066); // equivalent call
}
void std98::usePrinterEx() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);

    std::cout << "std98::PrinterEx\n";
    const detail::PrinterEx vis = std::for_each(vec.begin(), vec.end(), detail::PrinterEx());
    std::cout << "num calls: " << vis._CallCnt << '\n';
}

namespace std98 {
size_t bind2nd() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(6);
    v.push_back(9);
    // .. push back until 9...
    const size_t smaller5 = std::count_if(v.begin(), v.end(),
        std::bind2nd(std::less<int>(), 5)); // yields 'return < 5', std::bind1st std::bind2nd etc deprecated in C++11
    return smaller5;
}

// int stdBind() {
//     using std::placeholders::_1;
    
//     std::vector<int> v;
//     v.push_back(1);
//     v.push_back(2);
//     // push_back until 9...
//     const size_t val = std::count_if(v.begin(), v.end(),
//     std::bind(std::logical_and<bool>(), // error: ‘bind’ is not a member of ‘std’ in C++98
//     std::bind(std::greater<int>(),_1, 2),
//     std::bind(std::less_equal<int>(),_1,6)));
//     return val;
// }
}