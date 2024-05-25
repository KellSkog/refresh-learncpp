#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "header.hpp"
#include <algorithm>
#include <exception>
#include <iostream>
#include <memory> // smart pointers
#include <system_error> // Throw
#include <vector>

void doItLikeCPP() {
    std::cout << "Printed by C++, called from C" << "\n";
}

template <typename T>
T add(T x, T y, T z) {
    return x + y + z;
}

struct File {
    File(const char* path, bool write) {
        auto file_mode = write ? "w" : "r";
        file_pointer = fopen(path, file_mode);
        if (!file_pointer) throw std::system_error(errno, std::system_category());
    }
    ~File() {
        fclose(file_pointer);
    }
    FILE* file_pointer;
};


TEST_CASE("shuffle-the-array") {
    SUBCASE("example1") {
        std::vector<int> x{ 0, 1, 8, 13, 5, 2, 3 };
        x[0] = 21;
        x.push_back(1);
        std::sort(x.begin(), x.end());
        std::cout << "Printing " << x.size() << " Fibonacci numbers.\n";
        for (auto number : x) {
        std::cout << number << std::endl;
        }
        CHECK_EQ(x.size(), 8);
        CHECK_EQ(x[0], 1);
        CHECK_EQ(x[1], 1);
        CHECK_EQ(x[2], 2);
        CHECK_EQ(x[3], 3);
        CHECK_EQ(x[4], 5);
        CHECK_EQ(x[5], 8);
        CHECK_EQ(x[6], 13);
        CHECK_EQ(x[7], 21);

        auto n_evens = std::count_if(x.begin(), x.end(),
            [] (auto number) { return number % 2 == 0; });
        CHECK_EQ(n_evens, 2);

        double d1=1.1, d2=2.2, d3= 3.3;
        int i1=11, i2=22, i3=33;
        CHECK_GT(add(d1,d2,d3), 6.599);
        CHECK_LT(add(d1,d2,d3), 6.601);
        CHECK_EQ(add(i1,i2,i3), 66);
    }
    SUBCASE("example2") {
        Hal hal{9000};
        Hal::zing("Zing a song\n");
        hal.sing();
        hal.sing("Sing a song\n");
        // Listing 22
        auto halal = new Hal(42);
        CHECK_EQ(halal->_version, 42);
        delete halal;
    }
    SUBCASE("Listing 24") {
        try {
            auto file{File("listing24.txt", true)};
            const auto msg{"Hello world"};
            fwrite(msg, strlen(msg), 1, file.file_pointer);
        } catch (const std::exception &e) {
            std::cout << "Unable to write file\n";
        }
        try {
            auto file{File("listing24.txt", false)};
            char read_msg[13];
            fread(read_msg, sizeof(read_msg),1, file.file_pointer);
            CHECK_EQ(strcmp(read_msg, "Hello world"), 0);
            CHECK_LT(strcmp(read_msg, "Hello worlds"), 0);
            CHECK_GT(strcmp(read_msg, "Gello world"), 0);
        } catch (const std::exception &e) {
            std::cout << "Unable to read file\n";
        }

    }
    SUBCASE("Listing 26") {
        struct Foundation{
            Foundation(std::string founder) : _founder{founder} {}
            ~Foundation(){
                std::cout << "Foundation destroyed\n";
            }
            std::string _founder;
        };
        std::unique_ptr<Foundation> second_foundation{ new Foundation{"Wanda"} };
        std::cout << second_foundation->_founder << "\n";
    }
    SUBCASE("Listing 27") {
        struct Foundation{
            Foundation(std::string founder) : _founder{founder} {}
            std::string _founder;
        };
        struct Mutant {
            // Constructor sets foundation appropriately:
            Mutant(std::unique_ptr<Foundation> foundation)
            : foundation(std::move(foundation)) {}
            std::unique_ptr<Foundation> foundation;
        };
        std::unique_ptr<Foundation> second_foundation{ new Foundation{"Fish"} };
        // ... use second_foundation
        Mutant the_mule{ std::move(second_foundation) };
        // second_foundation is in a 'moved-from' state
        // the_mule owns the Foundation
        std::cout << the_mule.foundation->_founder << "\n";
        CHECK_EQ(second_foundation, nullptr);
    }
}