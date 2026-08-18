#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Step 1: Sort the array. This is crucial for the two-pointer approach 
        // and makes it extremely easy to skip duplicate values.
        sort(nums.begin(), nums.end());
        
        // Step 2: Iterate through the array, fixing one number at a time
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate values for our first number to ensure unique triplets
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Set up two pointers for the remaining portion of the array
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    // We found a valid triplet!
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the 'left' pointer to avoid duplicate triplets
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // Skip duplicates for the 'right' pointer
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    // Move both pointers inward to look for the next potential pair
                    left++;
                    right--;
                    
                } else if (sum < 0) {
                    // If the sum is too small, we need a larger number.
                    // Moving the left pointer to the right gives us a larger value (because it's sorted).
                    left++;
                } else {
                    // If the sum is too large, we need a smaller number.
                    // Moving the right pointer to the left gives us a smaller value.
                    right--;
                }
            }
        }
        
        return result;
    }
};