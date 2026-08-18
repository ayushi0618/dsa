#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // Map each Roman numeral character to its integer value
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            // If the current numeral is smaller than the next one, we subtract its value.
            // For example, in IV, I (1) is less than V (5), so we subtract 1.
            if (i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
                total -= roman[s[i]];
            } else {
                // Otherwise, we simply add its value.
                total += roman[s[i]];
            }
        }
        
        return total;
    }
};