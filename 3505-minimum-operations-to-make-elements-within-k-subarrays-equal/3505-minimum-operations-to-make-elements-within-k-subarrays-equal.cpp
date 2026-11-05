#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> cost(n - x + 1, 0);
        
        multiset<long long> left_half, right_half;
        long long left_sum = 0, right_sum = 0;
        
        int target_left = (x + 1) / 2;

        auto balance = [&]() {
            while (left_half.size() > target_left) {
                long long v = *left_half.rbegin();
                left_half.erase(prev(left_half.end()));
                left_sum -= v;
                right_half.insert(v);
                right_sum += v;
            }
            while (left_half.size() < target_left && !right_half.empty()) {
                long long v = *right_half.begin();
                right_half.erase(right_half.begin());
                right_sum -= v;
                left_half.insert(v);
                left_sum += v;
            }
        };

        auto add = [&](long long val) {
            if (left_half.empty() || val <= *left_half.rbegin()) {
                left_half.insert(val);
                left_sum += val;
            } else {
                right_half.insert(val);
                right_sum += val;
            }
            balance();
        };

        auto remove_val = [&](long long val) {
            auto it = left_half.find(val);
            if (it != left_half.end()) {
                left_half.erase(it);
                left_sum -= val;
            } else {
                it = right_half.find(val);
                if (it != right_half.end()) {
                    right_half.erase(it);
                    right_sum -= val;
                }
            }
            balance();
        };

        for (int i = 0; i < x; ++i) {
            add(nums[i]);
        }
        
        auto get_cost = [&]() {
            long long median = *left_half.rbegin();
            return (left_half.size() * median - left_sum) + (right_sum - right_half.size() * median);
        };

        cost[0] = get_cost();
        for (int i = x; i < n; ++i) {
            remove_val(nums[i - x]);
            add(nums[i]);
            cost[i - x + 1] = get_cost();
        }

        // DP to pick k non-overlapping windows of size x
        int m = cost.size();
        vector<long long> prev_dp(m + 1, 1e18);
        vector<long long> curr_dp(m + 1, 1e18);

        long long min_val = 1e18;
        for (int i = 0; i < m; ++i) {
            min_val = min(min_val, cost[i]);
            prev_dp[i + 1] = min_val;
        }

        for (int j = 2; j <= k; ++j) {
            fill(curr_dp.begin(), curr_dp.end(), 1e18);
            long long best_prev = 1e18;
            for (int i = x * (j - 1); i < m; ++i) {
                best_prev = min(best_prev, prev_dp[i - x + 1]);
                if (best_prev != 1e18) {
                    curr_dp[i + 1] = best_prev + cost[i];
                }
            }
            for (int i = 1; i <= m; ++i) {
                curr_dp[i] = min(curr_dp[i], curr_dp[i - 1]);
            }
            prev_dp = curr_dp;
        }

        return prev_dp[m];
    }
};