#include <iostream>

#include "stuff.hpp"

size_t Philosofy::count_dots(std::string_view str) {
    return std::count(std::begin(str), std::end(str), '.');
}

template<class T1, class T2> T1 Philosofy::MyPair<T1, T2>::firstMember() const {return first_;}
template<class T1, class T2> T2 Philosofy::MyPair<T1, T2>::secondMember() const {return second_;}

template<typename T1, typename T2>
std::ostream &Philosofy::operator<<(std::ostream &stream, const MyPair<T1, T2>
&mp) {
    stream << mp.firstMember() << ", ";
    stream << mp.secondMember();
    return stream;
}
/* Template Instantiation: This is the process where the compiler creates a specific 
 * function or class from a template definition.
 * This can be placed before the template definition!*/
template std::ostream &Philosofy::operator<<(std::ostream &, const MyPair<int, int> &);

/* Template Specialization: This allows you to define a different implementation 
 * of a template for a specific type or set of types.*/
template<>
std::ostream &Philosofy::operator<<(std::ostream &stream, [[maybe_unused]] const MyPair<int, double>
&mp) {
    stream << "Oh no not an int and a double =:-o\n";
    return stream;
}

void Philosofy::FrontEndDev::developFrontEnd() {}
void Philosofy::BackEndDev::developBackEnd() {}

inline void Philosofy::Proj::deliver() {
    for (auto &developer : developers_) {
        developer->develop();
    }
}

void Philosofy::FrontEndDev2::developFrontEnd() {
    std::cout << "Developing front end stuff\n";
}
void Philosofy::BackEndDev2::developBackEnd() {
    std::cout << "Developing back end stuff\n";
}
template<class... Devs> void Philosofy::Project2<Devs...>::deliver() {
    for (auto &developer : developers_) {
            std::visit([](auto &dev) { dev.develop(); }, developer);
    }
}
/* Instantiate template*/
template void Philosofy::Project2<Philosofy::FrontEndDev2, Philosofy::BackEndDev2>::deliver();