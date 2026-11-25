#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n == 1) return 1;

        // Coordinate compress nums to [0, m)
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        vector<int> s(n);
        for (int i = 0; i < n; ++i) {
            s[i] = static_cast<int>(lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin());
        }

        // Suffix array via prefix doubling
        vector<int> sa(n), rnk(n), tmp(n);
        for (int i = 0; i < n; ++i) {
            sa[i] = i;
            rnk[i] = s[i];
        }

        for (int k = 1; k < n; k <<= 1) {
            auto cmp = [&](int a, int b) {
                if (rnk[a] != rnk[b]) return rnk[a] < rnk[b];
                int ra = (a + k < n) ? rnk[a + k] : -1;
                int rb = (b + k < n) ? rnk[b + k] : -1;
                return ra < rb;
            };
            sort(sa.begin(), sa.end(), cmp);

            tmp[sa[0]] = 0;
            for (int i = 1; i < n; ++i) {
                tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
            }
            rnk = tmp;
            if (rnk[sa[n - 1]] == n - 1) break;
        }

        // Kasai's algorithm for LCP array: lcp[i] = LCP(sa[i-1], sa[i])
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) pos[sa[i]] = i;

        vector<int> lcp(n, 0);
        int h = 0;
        for (int i = 0; i < n; ++i) {
            if (pos[i] == 0) {
                h = 0;
                continue;
            }
            int j = sa[pos[i] - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h]) {
                ++h;
            }
            lcp[pos[i]] = h;
            if (h > 0) --h;
        }

        int ans = n;
        for (int i = 0; i < n; ++i) {
            int p = pos[i];
            int max_dup = 0;
            if (p > 0) max_dup = max(max_dup, lcp[p]);
            if (p + 1 < n) max_dup = max(max_dup, lcp[p + 1]);

            int candidate = max_dup + 1;
            if (candidate <= n - i) {
                ans = min(ans, candidate);
            }
        }

        return ans;
    }
};