#include <string>

class Solution {
public:
    string digitSum(string s, int k) {
        // Repeat the process as long as the length of s is strictly greater than k
        while (s.length() > k) {
            string next_s = "";
            
            // Step 1 & 2: Divide into consecutive groups of size k and calculate digit sums
            for (int i = 0; i < s.length(); i += k) {
                int current_sum = 0;
                string group = s.substr(i, k);
                
                for (char c : group) {
                    current_sum += (c - '0');
                }
                
                // Step 3: Append the sum as a string to our new string
                next_s += to_string(current_sum);
            }
            
            s = next_s;
        }
        
        return s;
    }
};