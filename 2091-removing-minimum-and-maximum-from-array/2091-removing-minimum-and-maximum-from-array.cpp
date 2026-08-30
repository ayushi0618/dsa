class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        
        // Ensure minIdx is the smaller index and maxIdx is the larger index for easier calculation
        if (minIdx > maxIdx) {
            swap(minIdx, maxIdx);
        }
        
        int option1 = maxIdx + 1;                  // Both removed from the front
        int option2 = n - minIdx;                  // Both removed from the back
        int option3 = (minIdx + 1) + (n - maxIdx); // One from front, one from back
        
        return min({option1, option2, option3});
    }
};