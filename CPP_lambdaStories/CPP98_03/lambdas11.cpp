#include <algorithm>
#include <functional> // std::bind
#include <iostream>
#include <vector>

#include "lambdas.hpp"
namespace std11 {
void doIt() {
    std::cout << "Doing it C++11 style\n";
}

namespace detail {
class PrinterEx {
    public:
        PrinterEx() {}
        void operator()(int x) {
            std::cout << x << '\n';
            ++_CallCnt;
        }
        /* int count() const {return n;}: In this function, const is applied to the function itself.
        This is known as a const member function. This means that the function does not modify the
        object it belongs to. It can be called on both const and non-const objects.*/
        int count() const {
            return _CallCnt;
        }
    private:
    int _CallCnt = 0; // Not allowed in C++98: warning: non-static data member initializers only available with ‘-std=c++11’ or ‘-std=gnu++11’
};
}

void usePrinterEx() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    
    std::cout << "std11::PrinterEx\n";
    const detail::PrinterEx vis2 = std::for_each(vec.begin(), vec.end(), detail::PrinterEx());
    std::cout << "num calls: " << vis2.count() << '\n';
}

/** Can not be compiled with c++98
 * error: template argument for 
 * ‘template<class _IIter, class _Funct> 
 * _Funct std::for_each(_IIter, _IIter, _Funct)’ 
 * uses local type ‘useLocalFunctionObject()::LocalPrinter’
*/
void useLocalFunctionObject() {
    std::cout << "LocalFunctionObject\n";
    struct LocalPrinter {
        void operator()(int x) const {
        std::cout << x << '\n';
        }
    };
    std::vector<int> v(10, 1);
    std::for_each(v.begin(), v.end(), LocalPrinter());
}

int stdBind() {
    using std::placeholders::_1;
    
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    // push_back until 9...
    const size_t val = std::count_if(v.begin(), v.end(),
    std::bind(std::logical_and<bool>(),
    std::bind(std::greater<int>(), _1, 2),
    std::bind(std::less_equal<int>(), _1, 6))); // return x > 2 && x <= 6;

    return val;
}
}