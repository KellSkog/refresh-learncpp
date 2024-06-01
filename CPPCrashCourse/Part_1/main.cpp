#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <array>
#include <cstddef>
#include <typeinfo>
#include <variant>

#include "stuff.hpp"

// #include <utility> // std::to_underlying (since C++23)

/*First we crawl. Later we crawl on broken glass.
    —Scott Meyers, Effective STL

  Python, Go, and Java have import.
  Rust, PHP, and C# have use/using.
  JavaScript, Lua, R, and Perl have require/requires.
  C and C++ have #include.*/

template<typename T>
    int step_function(T a) {
        auto res = a <=> 0;
        return (res < 0) ? -1 : (res > 0) ? 1 : 0;
    }
    enum class Modes{Start, Run, Done};

struct ClockOfTheLongNow {
    ClockOfTheLongNow(int year) : _year{year} {}
    int _year;
    int get_year() const {
        return _year;
    }
private:
    int year;
};
/* Had get_year not been marked a const method, is_leap_year would not
compile because clock is a const reference and cannot be modified within
is_leap_year.
declaration is incompatible with previous "is_leap_year" (declared at line 37)C/C++(159)*/
bool is_leap_year(const ClockOfTheLongNow& clock) {
    //This extra leap day occurs in each year that is a multiple of 4, 
    // except for years evenly divisible by 100 but not by 400.
    if (clock.get_year() % 4 > 0) return false;
    if (clock.get_year() % 100 > 0) return true;
    if (clock.get_year() % 400 > 0) return false;
    return true;
}

int power_up_rat_thing(int nuclear_isotopes) {
    static int rat_things_power = 200;
    rat_things_power += nuclear_isotopes;
    const auto waste_heat = rat_things_power * 20;
    if (waste_heat > 10000) {
        std::cout << "Warning! Hot doggie!\n";
    }
    return rat_things_power;
}

TEST_CASE("Part_1") {
    SUBCASE("up and running") {
        int num1 = 42;
        int num2 = 0;
        int num3 = -327;

        CHECK_EQ(step_function(num1), 1);
        CHECK_EQ(step_function(num2), 0);
        CHECK_EQ(step_function(num3), -1);
    }
    SUBCASE("Types") {
        auto x = 0;
        std::cout << "x has type: " << typeid(x).name() << '\n';
        std::byte y{0xff};
        CHECK_EQ(std::to_integer<int>(y >> 1), 0x7f);

        size_t z{42};
        CHECK_EQ(sizeof(z), 8);

        /* Printing Unicode to the console is surprisingly complicated
        char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";
        std::cout << chinese << "\n"; */
        for(auto mode : std::array<Modes, 3>{Modes::Start, Modes::Run, Modes::Done}) {
            switch(mode) {
                case Modes::Start : ;
                case Modes::Run : ;
                case Modes::Done : ;
            }
        }

        std::variant<const char*, int, double> v;
        v = 42;
        CHECK_EQ(std::get<int>(v), 42);
        v = 3.14159265;
        CHECK_EQ(std::get<double>(v), 3.14159265);
        v = "123456789";
        CHECK_EQ(strcmp(std::get<const char*>(v), "123456789"), 0);

        #if 0
        float a{ 1 };
        float b{ 2 };
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wconversion"
        /* The pragmas doesn't work???? */
            int narrowed_result(a/b); // Potentially nasty narrowing conversion
            // g++ (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0 add_compile_options( -Wconversion) =>
            // error: conversion from ‘float’ to ‘int’ may change value [-Werror=float-conversion]
            CHECK_EQ(narrowed_result, 0);
            int result{ a/b }; // Compiler generates warning, allways can't be shut off!
            // g++ (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0 add_compile_options( -Wconversion) =>
            // error: conversion from ‘float’ to ‘int’ may change value [-Werror=float-conversion]
            CHECK_EQ(result, 0);
        #endif
        #pragma GCC diagnostic pop //restores the diagnostics to the state saved by the last push.

        /* Initializing Class Members */
        // It’s not possible to use parentheses to initialize member variables.
        //  Here’s a general rule to make initialization simple: use braced initializers everywhere.
        struct JohanVanDerSmut {
            bool gold = true;
            int year_of_smelting_accident{ 1970 };
            char key_location[8] = { "x-rated" };
        };
    } // SUBCASE("Types")
    SUBCASE("Reference Types") {
        int gettysburg{};
        std::cout << "Gettysburg: " << gettysburg << "\n";
        std::cout << "Gettysburg's address: " << &gettysburg << "\n";

        // At the slightest provocation, an array will decay into a pointer.
        std::array<int, 3> keyToTheUniverse{1,2,3};
        std::cout << "keyToTheUniverse address: " << keyToTheUniverse.data() << "\n";
        int keyToTheOtherUniverse[]{1,2,3};
        std::cout << "keyToTheOtherUniverse address: " << keyToTheOtherUniverse << "\n";
        std::cout << "keyToTheOtherUniverse address: " << &keyToTheOtherUniverse << "\n";
        // int* ptrToOtherUni = &keyToTheOtherUniverse; //a value of type "int (*)[3]" cannot be used to initialize an entity of type "int *"C/C++(144)
        int* ptrToOtherUni = keyToTheOtherUniverse;
        std::cout << "keyToTheOtherUniverse address: " << ptrToOtherUni << "\n";

        ClockOfTheLongNow today{2024};
        CHECK(is_leap_year(today));
        CHECK(is_leap_year(ClockOfTheLongNow{1600}));
        CHECK(is_leap_year(ClockOfTheLongNow{2000}));
        CHECK_FALSE(is_leap_year(ClockOfTheLongNow{1700}));
        CHECK_FALSE(is_leap_year(ClockOfTheLongNow{1800}));
        CHECK_FALSE(is_leap_year(ClockOfTheLongNow{1900}));
        CHECK_FALSE(is_leap_year(ClockOfTheLongNow{2100}));
        CHECK_FALSE(is_leap_year(ClockOfTheLongNow{2200}));
        CHECK_FALSE(is_leap_year(ClockOfTheLongNow{2300}));

        [[maybe_unused]] int answer = 42;
        [[maybe_unused]] auto the_answer { answer }; // int
        [[maybe_unused]] auto foot { 12L }; // long
        [[maybe_unused]] auto rootbeer { 5.0F }; // float
        [[maybe_unused]] auto cheeseburger { 10.0 }; // double
        [[maybe_unused]] auto politifact_claims { false }; // bool
        [[maybe_unused]] auto cheese { "string" }; // char[7]
        [[maybe_unused]] auto same_answer = 42;
        [[maybe_unused]] auto otherFoot(12L);

        // As a general rule, use auto always.
        SUBCASE("4. The Object Life Cycle") {
        /*  1. The object’s storage duration begins, and storage is allocated.
            2. The object’s constructor is called.
            3. The object’s lifetime begins.
            4. You can use the object in your program.
            5. The object’s lifetime ends.
            6. The object’s destructor is called.
            7. The object’s storage duration ends, and storage is deallocated.*/
            CHECK_EQ(power_up_rat_thing(100), 300);
            CHECK_EQ(power_up_rat_thing(100), 400);
            CHECK_EQ(power_up_rat_thing(200), 600);

            struct Marxx{
                void forget(int x) {
                    if (x == 0xFACE) {
                        throw std::runtime_error{ "I'd be glad to make an exception." };
                    }
                    std::cout << std::hex << "Forgot "<< x << std::dec << "\n";
                }
            };
            Marxx grucho{};
            try {
                grucho.forget(42);
                grucho.forget(0xFACE);
            } catch(const std::runtime_error& e) {
                std::cout << "exception caught with message: " << e.what() << "\n";
            }
        }

        SUBCASE("5. The philosophy of C++") {
            /* In short, it can be summarized by three rules:
             * 1. There should be no language beneath C++ (except assembly).
             * 2. You only pay for what you use.
             * 3. Offer high-level abstractions at low cost (there's a strong aim for zero-cost) */
            std::string dots{"This. String.. Has. A few ..."};
            CHECK_EQ(Philosofy::count_dots(dots), 7);
            Philosofy::MyPair myPair{42, 42};
            std::cout << myPair << "\n";
            Philosofy::MyPair myPair2{42, 42.5};
            std::cout << myPair2 << "\n";
        }
    }
} // TEST_CASE("Part_1")