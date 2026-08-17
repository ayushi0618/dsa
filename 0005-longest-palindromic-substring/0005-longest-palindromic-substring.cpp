class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLen = 0;
        
        // Helper lambda to expand outwards from a given center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            // Length of the current palindrome is (right - 1) - (left + 1) + 1 = right - left - 1
            return right - left - 1; 
        };
        
        for (int i = 0; i < s.length(); i++) {
            // Check for odd-length palindromes (center is at character i)
            int len1 = expandAroundCenter(i, i);
            
            // Check for even-length palindromes (center is between i and i + 1)
            int len2 = expandAroundCenter(i, i + 1);
            
            int len = max(len1, len2);
            
            // If a longer palindrome is found, update the max length and the starting index
            if (len > maxLen) {
                maxLen = len;
                // Calculate the start index based on the center 'i' and the total length
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLen);
    }
};