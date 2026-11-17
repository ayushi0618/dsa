class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        
        // cost[i][j] stores the min changes to make s[i...j] a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        
        // Precompute cost for all substrings of length >= 2
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                int min_changes = 1e9;
                
                // Check all proper divisors d of len
                for (int d = 1; d < len; ++d) {
                    if (len % d == 0) {
                        int changes = 0;
                        // Check each of the d groups
                        for (int offset = 0; offset < d; ++offset) {
                            int l = i + offset;
                            int r = i + len - d + offset;
                            while (l < r) {
                                if (s[l] != s[r]) {
                                    changes++;
                                }
                                l += d;
                                r -= d;
                            }
                        }
                        min_changes = min(min_changes, changes);
                    }
                }
                cost[i][j] = min_changes;
            }
        }
        
        // dp[i][parts] = min changes to partition s[i...n-1] into 'parts' semi-palindromes
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
        dp[0][0] = 0;
        
        for (int parts = 1; parts <= k; ++parts) {
            for (int i = 0; i < n; ++i) {
                // Try all possible end points `j` for the current substring s[i...j]
                for (int j = i + 1; j < n; ++j) {
                    // Remaining characters after j must be enough to form (k - parts) parts
                    if (n - 1 - j >= k - parts) {
                        if (dp[i][parts - 1] != 1e9) { // Note: adjusted indexing for standard partition DP
                            // Actually, standard state: dp[i][parts] = min over j of (cost[i][j] + dp[j+1][parts-1])
                        }
                    }
                }
            }
        }
        
        // Cleaner bottom-up DP formulation:
        // dp[i][p] -> min changes to partition prefix s[0...i] into p parts
        vector<vector<int>> dp2(n + 1, vector<int>(k + 1, 1e9));
        dp2[0][0] = 0;
        
        for (int p = 1; p <= k; ++p) {
            for (int i = 1; i <= n; ++i) {
                // Try splitting at index j (where substring is s[j...i-1])
                for (int j = (p - 1) * 2; j <= i - 2; ++j) {
                    if (dp2[j][p - 1] != 1e9) {
                        dp2[i][p] = min(dp2[i][p], dp2[j][p - 1] + cost[j][i - 1]);
                    }
                }
            }
        }
        
        return dp2[n][k];
    }
};