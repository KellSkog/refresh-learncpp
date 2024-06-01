#include <algorithm>
#include <ostream>
#include <string_view>

namespace Philosofy {
    size_t count_dots(std::string_view str);

    template<typename T1, typename T2>
    struct MyPair {
        MyPair(T1 first, T2 second) : first_{first}, second_{second} {}
        T1 firstMember() const;
        T2 secondMember() const;
        T1 first_;
        T2 second_;
    };
    /* Note that our implementation of operator<< is a free (non-member) function. You should
     * prefer those to member functions if possible as it actually helps encapsulation*/
    template<typename T1, typename T2>
    std::ostream &operator<<(std::ostream &stream, const MyPair<T1, T2> &mp);

}