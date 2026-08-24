class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<long long> pref(n);
        pref[0] = stones[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + stones[i];
        }

        // Base case: if we are at the last possible move, 
        // the score difference is simply the sum of all remaining stones.
        long long res = pref[n - 1];

        // Traverse backwards to find the maximum score difference
        for (int i = n - 2; i >= 1; --i) {
            res = max(res, pref[i] - res);
        }

        return res;
    }
};