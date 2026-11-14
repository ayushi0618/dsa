#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minimumSumSubarray(std::vector<int>& nums, int l, int r) {
        int min_sum = INT_MAX;
        int n = nums.size();
        
        // Try all possible starting points
        for (int i = 0; i < n; ++i) {
            int current_sum = 0;
            // Try all possible lengths from l to r
            for (int j = i; j < n; ++j) {
                current_sum += nums[j];
                int len = j - i + 1;
                
                if (len >= l && len <= r) {
                    if (current_sum > 0) {
                        min_sum = std::min(min_sum, current_sum);
                    }
                }
                
                // If length exceeds r, we can stop the inner loop for this start index
                if (len > r) {
                    break;
                }
            }
        }
        
        return (min_sum == INT_MAX) ? -1 : min_sum;
    }
};