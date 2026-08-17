class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // DP table to store the max score for subarray from index 'left' to 'right'
        vector<vector<int>> memo(n, vector<int>(n, -1));
        
        // Prefix sum array to get subarray sums in O(1) time
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        // Recursive lambda function for our DP
        function<int(int, int)> dp = [&](int left, int right) {
            // Base case: Only one stone left, game ends, score is 0 for this turn
            if (left == right) return 0;
            
            // Return precalculated results
            if (memo[left][right] != -1) return memo[left][right];

            int max_score = 0;
            
            // Try splitting the array at every possible index 'i' between 'left' and 'right - 1'
            for (int i = left; i < right; ++i) {
                int left_sum = prefix[i + 1] - prefix[left];
                int right_sum = prefix[right + 1] - prefix[i + 1];

                if (left_sum < right_sum) {
                    // Bob throws away the right row, Alice keeps the left row
                    max_score = max(max_score, left_sum + dp(left, i));
                } else if (left_sum > right_sum) {
                    // Bob throws away the left row, Alice keeps the right row
                    max_score = max(max_score, right_sum + dp(i + 1, right));
                } else {
                    // Sums are equal, Alice gets to decide which one to keep
                    // She will obviously pick the one that yields the maximum future score
                    max_score = max(max_score, left_sum + max(dp(left, i), dp(i + 1, right)));
                }
            }
            
            return memo[left][right] = max_score;
        };

        return dp(0, n - 1);
    }
};