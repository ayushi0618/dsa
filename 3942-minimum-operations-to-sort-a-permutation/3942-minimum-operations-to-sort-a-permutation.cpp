class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1) return 0;

        int pos0 = -1;
        for (int i = 0; i < n; i++)
            if (nums[i] == 0) pos0 = i;

        const int INF = 1e9;
        int ans = INF;

        // Case A: nums is a rotation of [0,1,...,n-1]
        bool rot = true;
        for (int i = 0; i < n; i++) {
            if (nums[(i + 1) % n] != (nums[i] + 1) % n) { rot = false; break; }
        }
        if (rot) {
            int m = pos0;  // left rotations needed
            ans = min(ans, min(m, n - m + 2));
        }

        // Case B: nums read cyclically decreases by 1 (reverse of a rotation)
        bool rev = true;
        for (int i = 0; i < n; i++) {
            if (nums[(i + 1) % n] != (nums[i] - 1 + n) % n) { rev = false; break; }
        }
        if (rev) {
            int j1 = (n - 1 - pos0) % n;  // reverse, then rotate left j1
            int j2 = (pos0 + 1) % n;      // rotate left j2, then reverse
            ans = min(ans, 1 + min(j1, j2));
        }

        return ans == INF ? -1 : ans;
    }
};
