#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int MOD = 1e9 + 7;

        // go[i][j][0] stores the landing {r, c} when moving right from (i, j)
        // go[i][j][1] stores the landing {r, c} when moving down from (i, j)
        vector<vector<vector<pair<int, int>>>> go(m, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(2, {-1, -1})));

        // Precompute jump targets
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // For move right (dir = 0)
                {
                    int r = i, c = j + 1;
                    int dir = 0; // 0 for right, 1 for down
                    bool valid = true;
                    while (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
                        if (dir == 0) {
                            // Entered mirror moving right -> turns down
                            dir = 1;
                            r += 1;
                        } else {
                            // Entered mirror moving down -> turns right
                            dir = 0;
                            c += 1;
                        }
                    }
                    if (r >= 0 && r < m && c >= 0 && c < n) {
                        go[i][j][0] = {r, c};
                    }
                }

                // For move down (dir = 1)
                {
                    int r = i + 1, c = j;
                    int dir = 1;
                    bool valid = true;
                    while (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
                        if (dir == 0) {
                            dir = 1;
                            r += 1;
                        } else {
                            dir = 0;
                            c += 1;
                        }
                    }
                    if (r >= 0 && r < m && c >= 0 && c < n) {
                        go[i][j][1] = {r, c};
                    }
                }
            }
        }

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0) continue;

                // Try moving right
                auto [nr1, nc1] = go[i][j][0];
                if (nr1 != -1) {
                    dp[nr1][nc1] = (dp[nr1][nc1] + dp[i][j]) % MOD;
                }

                // Try moving down
                auto [nr2, nc2] = go[i][j][1];
                if (nr2 != -1) {
                    dp[nr2][nc2] = (dp[nr2][nc2] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};