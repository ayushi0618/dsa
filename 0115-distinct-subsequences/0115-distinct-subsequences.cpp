#include <string>
#include <vector>

class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        int m = s.length(), n = t.length();
        // Using double for dp table to prevent potential 32-bit integer overflow 
        // during intermediate state calculations, though problem states answers fit in 32-bit signed int.
        std::vector<std::vector<double>> dp(m + 1, std::vector<double>(n + 1, 0));

        // Base case: empty t can be formed by 1 subsequence (deleting all chars)
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return static_cast<int>(dp[m][n]);
    }
};