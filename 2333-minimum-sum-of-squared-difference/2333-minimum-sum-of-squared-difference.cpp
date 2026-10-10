class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long total_k = (long long)k1 + k2;
        
        // Find the maximum difference to size our frequency array
        int max_diff = 0;
        vector<long long> count(100001, 0);
        
        for (int i = 0; i < n; ++i) {
            int diff = abs(nums1[i] - nums2[i]);
            count[diff]++;
            max_diff = max(max_diff, diff);
        }
        
        // Greedily reduce the largest differences
        for (int d = max_diff; d > 0 && total_k > 0; --d) {
            if (count[d] == 0) continue;
            
            // Number of operations needed to reduce all elements of difference `d` to `d - 1`
            long long ops = min(total_k, count[d]);
            count[d] -= ops;
            count[d - 1] += ops;
            total_k -= ops;
        }
        
        // Calculate the final sum of squared differences
        long long result = 0;
        for (int d = 1; d <= max_diff; ++d) {
            if (count[d] > 0) {
                result += count[d] * (long long)d * d;
            }
        }
        
        return result;
    }
};