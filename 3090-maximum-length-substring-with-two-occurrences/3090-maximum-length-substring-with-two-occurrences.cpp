class Solution {
public:
    int maximumLengthSubstring(string s) {
        // Array to store the frequency of each character (a-z)
        int count[26] = {0}; 
        int max_len = 0;
        int left = 0;

        // Expand the window by moving the right pointer
        for (int right = 0; right < s.length(); right++) {
            // Increment the frequency of the current character
            count[s[right] - 'a']++;

            // If the frequency exceeds 2, the window is invalid.
            // Shrink the window from the left until it becomes valid again.
            while (count[s[right] - 'a'] > 2) {
                count[s[left] - 'a']--;
                left++;
            }

            // Calculate the current valid window size and update max_len
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};