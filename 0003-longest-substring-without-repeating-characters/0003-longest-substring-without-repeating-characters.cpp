class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Array to store the last seen index of each ASCII character.
        // Initialize with -1 since index 0 is a valid position in the string.
        vector<int> charIndex(128, -1); 
        
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];
            
            // If we've seen the character before AND its last seen index is 
            // within our current window bounds, we must shrink the window.
            if (charIndex[currentChar] >= left) {
                // Move the left pointer just past the previous occurrence
                left = charIndex[currentChar] + 1;
            }
            
            // Update the last seen index of the current character
            charIndex[currentChar] = right;
            
            // Calculate the length of the current valid window and update maxLength
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};