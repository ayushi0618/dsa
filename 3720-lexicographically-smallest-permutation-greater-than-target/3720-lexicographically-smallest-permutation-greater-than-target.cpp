#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        string result = "";
        // Helper lambda or function to try building the rest of the string
        // using available character counts starting from index idx.
        // We can solve this cleanly using backtracking:
        
        auto canForm = [&](int idx, string& current, vector<int>& cnt) {
            if (idx == n) return true;
            
            // Try to match target[idx] if possible
            int t_char = target[idx] - 'a';
            
            // 1. Try exact match first if we want to stay equal as long as possible,
            // but here we need strictly greater. We can branch into trying greater characters.
            // A more robust approach is backtracking from left to right.
            return false; // placeholder for full recursive logic
        };
        
        // Complete backtracking implementation:
        vector<int> initial_count = count;
        string ans = "";
        
        auto solve = [&](auto& self, int idx, bool isGreater) -> bool {
            if (idx == n) return isGreater;
            
            int start = isGreater ? 0 : (target[idx] - 'a');
            for (int c = start; c < 26; ++c) {
                if (count[c] > 0) {
                    count[c]--;
                    ans.push_back('a' + c);
                    
                    bool nextGreater = isGreater || (c > (target[idx] - 'a'));
                    if (self(self, idx + 1, nextGreater)) {
                        return true;
                    }
                    
                    ans.pop_back();
                    count[c]++;
                }
            }
            return false;
        };

        if (solve(solve, 0, false)) {
            return ans;
        }
        return "";
    }
};