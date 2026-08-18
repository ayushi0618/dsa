#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        
        // Count the overall frequency of each number in the array
        for (int num : nums) {
            freq[num]++;
        }
        
        // Case 1: The subarray size is the entire array
        if (k == n) {
            int max_val = -1;
            for (int num : nums) {
                max_val = max(max_val, num);
            }
            return max_val;
        }
        
        // Case 2: The subarray size is exactly 1
        if (k == 1) {
            int max_val = -1;
            for (auto const& [num, count] : freq) {
                if (count == 1) {
                    max_val = max(max_val, num);
                }
            }
            return max_val;
        }
        
        // Case 3: 1 < k < n
        int max_val = -1;
        // Only the first and last elements can possibly appear in exactly ONE subarray of size k.
        if (freq[nums[0]] == 1) {
            max_val = max(max_val, nums[0]);
        }
        if (freq[nums[n - 1]] == 1) {
            max_val = max(max_val, nums[n - 1]);
        }
        
        return max_val;
    }
};