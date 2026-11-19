#include <algorithm>
#include <vector>

class Solution {
public:
    int minimizeSum(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n <= 3) return 0;

        std::sort(nums.begin(), nums.end());

        int option1 = nums[n - 1] - nums[2];
        int option2 = nums[n - 3] - nums[0];
        int option3 = nums[n - 2] - nums[1];

        return std::min({option1, option2, option3});
    }
};