class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, 1e18);
        dp[0] = 0;
        
        for (int j = 1; j <= n; ++j) {
            for (int i = max(0, j - 3); i < j; ++i) {
                long long cost = dp[i] + costs[j - 1] + (long long)(j - i) * (j - i);
                dp[j] = min(dp[j], cost);
            }
        }
        
        return dp[n];
    }
};