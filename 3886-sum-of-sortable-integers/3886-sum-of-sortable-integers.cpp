
class Solution {
public:
    bool isRotation(vector<int>& nums, vector<int>& sorted,
                    int start, int k) {
        vector<int> pi(k, 0);

        // KMP prefix function for the sorted target block
        for (int i = 1; i < k; i++) {
            int j = pi[i - 1];

            while (j > 0 && sorted[start + i] != sorted[start + j]) {
                j = pi[j - 1];
            }

            if (sorted[start + i] == sorted[start + j]) {
                j++;
            }

            pi[i] = j;
        }

        // Search target in the circular original block
        int j = 0;

        for (int i = 0; i < 2 * k - 1; i++) {
            int value = nums[start + i % k];

            while (j > 0 && value != sorted[start + j]) {
                j = pi[j - 1];
            }

            if (value == sorted[start + j]) {
                j++;
            }

            if (j == k) {
                return true;
            }
        }

        return false;
    }

    bool check(vector<int>& nums, vector<int>& sorted, int k) {
        int n = nums.size();

        for (int start = 0; start < n; start += k) {
            if (!isRotation(nums, sorted, start, k)) {
                return false;
            }
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int ans = 0;

        for (int d = 1; d * d <= n; d++) {
            if (n % d != 0) {
                continue;
            }

            int k1 = d;
            int k2 = n / d;

            if (check(nums, sorted, k1)) {
                ans += k1;
            }

            if (k1 != k2 && check(nums, sorted, k2)) {
                ans += k2;
            }
        }

        return ans;
    }
};
