class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        long long cost = 0;
        // Monotonic stack/deque storing indices with nums[i] in non-increasing order from front to back
        deque<int> dq;
        
        int n = nums.size();
        for (int i = n - 1, j = n - 1; i >= 0; --i) {
            const int num = nums[i];
            while (!dq.empty() && nums[dq.back()] < num) {
                const int l = dq.back();
                dq.pop_back();
                const int r = dq.empty() ? j + 1 : dq.back();
                cost += static_cast<long long>(r - l) * (num - nums[l]);
            }
            dq.push_back(i);
            
            while (cost > k) {
                cost -= nums[dq.front()] - nums[j];
                if (dq.front() == j) {
                    dq.pop_front();
                }
                --j;
            }
            ans += j - i + 1;
        }
        
        return ans;
    }
};