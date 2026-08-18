#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // Map of integer values and their corresponding Roman numerals in descending order.
        // We include the subtractive edge cases (e.g., 900 = CM, 4 = IV) directly in the map.
        vector<pair<int, string>> roman_map = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        
        string result = "";
        
        // Iterate through the predefined values
        for (auto const& [val, sym] : roman_map) {
            // Keep subtracting the value and appending the symbol 
            // as long as the current number is large enough.
            while (num >= val) {
                result += sym;
                num -= val;
            }
        }
        
        return result;
    }
};