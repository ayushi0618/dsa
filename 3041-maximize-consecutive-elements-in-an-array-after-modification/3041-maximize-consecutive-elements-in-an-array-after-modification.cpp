#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        int ans = 0;

        for (int x : nums) {
            // Option 1: increment x to (x + 1), extending a run ending at x
            dp[x + 1] = dp[x] + 1;
            // Option 2: keep x as x, extending a run ending at (x - 1)
            dp[x] = dp[x - 1] + 1;

            ans = max({ans, dp[x + 1], dp[x]});
        }

        return ans;
    }
};