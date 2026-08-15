class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        bool hasNonZero = false;
        
        for (int num : nums) {
            totalXor ^= num;
            if (num != 0) {
                hasNonZero = true;
            }
        }
        
        // If the XOR of the entire array is non-zero, take all elements
        if (totalXor != 0) {
            return nums.size();
        }
        
        // If XOR is 0 but there is at least one non-zero element, 
        // we can remove one element to make the XOR non-zero
        if (hasNonZero) {
            return nums.size() - 1;
        }
        
        // If all elements are 0
        return 0;
    }
};