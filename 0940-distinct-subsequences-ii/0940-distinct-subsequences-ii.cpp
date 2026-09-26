class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD = 1e9 + 7;
        vector<long long> endWith(26, 0);
        
        for (char c : s) {
            long long total = 1; // Single character subsequence itself
            for (int i = 0; i < 26; ++i) {
                total = (total + endWith[i]) % MOD;
            }
            endWith[c - 'a'] = total;
        }
        
        long long ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + endWith[i]) % MOD;
        }
        
        return ans;
    }
};