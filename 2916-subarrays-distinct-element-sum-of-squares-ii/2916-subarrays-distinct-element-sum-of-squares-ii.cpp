class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        long long MOD = 1e9 + 7;
        
        // Segment tree arrays
        // tree stores the sum of squares, lazy stores the range increment
        vector<long long> tree(4 * n, 0), lazy(4 * n, 0), sum(4 * n, 0);
        
        auto push = [&](int node, int l, int r) {
            if (lazy[node] != 0) {
                int mid = (l + r) / 2;
                long long val = lazy[node];
                
                tree[2 * node] = (tree[2 * node] + 2 * val * sum[2 * node] + val * val * (mid - l + 1)) % MOD;
                sum[2 * node] = (sum[2 * node] + val * (mid - l + 1)) % MOD;
                lazy[2 * node] = (lazy[2 * node] + val) % MOD;
                
                tree[2 * node + 1] = (tree[2 * node + 1] + 2 * val * sum[2 * node + 1] + val * val * (r - mid)) % MOD;
                sum[2 * node + 1] = (sum[2 * node + 1] + val * (r - mid)) % MOD;
                lazy[2 * node + 1] = (lazy[2 * node + 1] + val) % MOD;
                
                lazy[node] = 0;
            }
        };

        auto update = [&](auto& self, int node, int l, int r, int ql, int qr, long long val) -> void {
            if (ql > r || qr < l) return;
            if (ql <= l && r <= qr) {
                tree[node] = (tree[node] + 2 * val * sum[node] + val * val * (r - l + 1)) % MOD;
                sum[node] = (sum[node] + val * (r - l + 1)) % MOD;
                lazy[node] = (lazy[node] + val) % MOD;
                return;
            }
            push(node, l, r);
            int mid = (l + r) / 2;
            self(self, 2 * node, l, mid, ql, qr, val);
            self(self, 2 * node + 1, mid + 1, r, ql, qr, val);
            tree[node] = (tree[2 * node] + tree[2 * node + 1]) % MOD;
            sum[node] = (sum[2 * node] + sum[2 * node + 1]) % MOD;
        };

        auto query = [&](auto& self, int node, int l, int r, int ql, int qr) -> long long {
            if (ql > r || qr < l) return 0;
            if (ql <= l && r <= qr) return tree[node];
            push(node, l, r);
            int mid = (l + r) / 2;
            return (self(self, 2 * node, l, mid, ql, qr) + 
                    self(self, 2 * node + 1, mid + 1, r, ql, qr)) % MOD;
        };

        unordered_map<int, int> last_pos;
        long long total_sum = 0;

        for (int j = 0; j < n; ++j) {
            int last = last_pos.count(nums[j]) ? last_pos[nums[j]] : -1;
            last_pos[nums[j]] = j;

            // Update range [last + 1, j] with +1
            update(update, 1, 0, n - 1, last + 1, j, 1);

            // Query total sum of squares of counts for all subarrays ending at j
            long long sub_sum = query(query, 1, 0, n - 1, 0, j);
            total_sum = (total_sum + sub_sum) % MOD;
        }

        return total_sum;
    }
};