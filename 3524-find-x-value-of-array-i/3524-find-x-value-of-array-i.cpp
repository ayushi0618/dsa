class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        // Tracks the count of subarrays ending at the previous position with each remainder modulo k
        vector<long long> prev_dp(k, 0);
        
        for (int num : nums) {
            vector<long long> curr_dp(k, 0);
            int rem = num % k;
            
            // A new subarray starting at the current element
            curr_dp[rem]++;
            
            // Extend all previous subarrays ending at the last index
            for (int r = 0; r < k; ++r) {
                if (prev_dp[r] > 0) {
                    int new_rem = (r * rem) % k;
                    curr_dp[new_rem] += prev_dp[r];
                }
            }
            
            // Add the current step's counts to the total result
            for (int r = 0; r < k; ++r) {
                result[r] += curr_dp[r];
            }
            
            prev_dp = move(curr_dp);
        }
        
        return result;
    }
};