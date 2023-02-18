/* https://open.kattis.com/problems/welcomeeasy
 * find a sequence 
 * of increasing indices into the input string such that the concatenation of 
 * is the string “welcome to code jam”. 
 */

#include <iomanip>
#include <iostream>
#include <string>

#include <limits>
constexpr std::string target{"welcome to code jam"}
constexpr int charCount = target.length(); // 19 characters C string, target[18] == 'm'

int main() {
    int subStrCnt = 0;
    int caseCount;

    std::cin >> caseCount;
    int caseNo = 1;
    while(caseNo <= caseCount) {
        int apperanceCount = 0;
        std::string input;
        std::getline(std::cin, input);
        for(int l1 = 0; l1 <= input.length() - charCount) { // Shall execute once with input "welcome to code jam"
            if(input[l1] != 'w') continue;
            for(int l2 = l1 + 1; l2 <= input.length() - charCount) { // Shall execute once with input "welcome to code jam"
                if(input[l2] != 'e') continue;
                ++apperanceCount;
            }
        }
        apperanceCount %= 10000;
        std::cout << "Case #" << std::setfill('0') << std::setw(4) << caseNo << ": " << apperanceCount << "\n";
        ++caseNo;
    }
}