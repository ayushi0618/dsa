class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        // dp[i][j][k] represents the max profit at cell (i, j) having neutralized k robbers (k = 0, 1, 2)
        // Initialize with a very small number to handle negative paths properly
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -1e9)));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k <= 2; ++k) {
                    if (i == 0 && j == 0) {
                        if (coins[i][j] < 0) {
                            dp[i][j][0] = coins[i][j]; // Cannot neutralize at start if it's negative unless we use a charge
                            if (k >= 1) dp[i][j][k] = 0; // Neutralize the robber at (0, 0)
                        } else {
                            dp[i][j][k] = coins[i][j];
                        }
                        continue;
                    }

                    int val = coins[i][j];

                    // Transition from top (i-1, j)
                    if (i > 0) {
                        // Without neutralizing current cell
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + val);
                        // By neutralizing current cell if it has a robber (val < 0)
                        if (val < 0 && k > 0) {
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
                        }
                    }

                    // Transition from left (i, j-1)
                    if (j > 0) {
                        // Without neutralizing current cell
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1 < 0 ? 0 : i][j - 1][k] + val);
                        // Wait, proper index for left is (i, j-1):
                        dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + val);
                        if (val < 0 && k > 0) {
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1]);
                        }
                    }
                }
            }
        }

        return max({dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});
    }
};