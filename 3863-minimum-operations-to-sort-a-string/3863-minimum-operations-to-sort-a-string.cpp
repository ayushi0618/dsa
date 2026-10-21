#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
        // Case 1: Already sorted
        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());
        if (s == sorted_s) {
            return 0;
        }
        
        // Case 2: Length 2 cannot be sorted if not already sorted
        if (n == 2) {
            return -1;
        }
        
        char mn = sorted_s[0];
        char mx = sorted_s[n - 1];
        
        // Case 3: Check if min is at the start (proper prefix) or max is at the end (proper suffix)
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }
        
        // Case 4: Check if min exists in any proper prefix and max exists in any proper suffix
        bool has_mn_prefix = false;
        bool has_mx_suffix = false;
        
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == mn) has_mn_prefix = true;
        }
        for (int i = 1; i < n; ++i) {
            if (s[i] == mx) has_mx_suffix = true;
        }
        
        if (!has_mn_prefix && !has_mx_suffix) {
            return 3;
        }
        
        // Otherwise, it can be sorted in 2 operations
        return 2;
    }
};