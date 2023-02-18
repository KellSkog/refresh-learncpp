#include <iostream>

#include <limits>

int main() {
    int guess;
    int lowLimit = std::numeric_limits<int>::min();
    int highLimit = std::numeric_limits<int>::max();
    std::string response;
    std::cin >> guess;
    while(guess != 0) {
        std::cin >> response;
        if(response[0] == 'r') { // right on
            // Game ended, new transcript maybe, report and reset
            if((guess < highLimit) && (guess  > lowLimit))
                std::cout << "Stan may be honest\n";
            else
                std::cout << "Stan is dishonest\n";
            lowLimit = std::numeric_limits<int>::min();
            highLimit = std::numeric_limits<int>::max();
        }
        // response holds "too"
        std::cin >> response;
        if(response[0] == 'h') { // too high
            if(guess < highLimit)
                highLimit = guess;
        } else if(response[0] == 'l') { // too low
            if(guess > lowLimit)
                lowLimit = guess;
        }
        std::cin >> guess;
    }
}