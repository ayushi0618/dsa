class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_val = nums[0];
        int total_moves = 0;
        
        // Find the maximum element in the array
        for (int num : nums) {
            if (num > max_val) {
                max_val = num;
            }
        }
        
        // Accumulate the difference between the max value and each element
        for (int num : nums) {
            total_moves += (max_val - num);
        }
        
        return total_moves;
    }
};