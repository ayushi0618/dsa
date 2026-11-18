#include <string>
#include <iostream>

class Solution {
public:
    int minChanges(std::string s) {
        int changes = 0;
        // Iterate through the string stepping by 2
        for (int i = 0; i < s.length(); i += 2) {
            // If the characters in the current block of 2 don't match, 1 change is required
            if (s[i] != s[i + 1]) {
                changes++;
            }
        }
        return changes;
    }
};