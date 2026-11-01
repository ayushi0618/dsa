class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_val = nums[0];
        long long total_sum = 0;
        
        for (int num : nums) {
            total_sum += num;
            if (num < min_val) {
                min_val = num;
            }
        }
        
        return total_sum - (long long)min_val * nums.size();
    }
};