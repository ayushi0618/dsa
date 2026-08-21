class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1, high = 2e15; // Safe upper bound since min(coins) * k can be large
        long long ans = high;
        
        // Helper to compute GCD
        auto gcd = [](long long a, long long b) {
            while (b) {
                long long temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        };

        // Helper to compute LCM with overflow protection
        auto lcm = [&](long long a, long long b) {
            if (a == 0 || b == 0) return 0LL;
            long long g = gcd(a, b);
            if (a / g > high / b) return high + 1; // Overflow guard
            return (a / g) * b;
        };

        int n = coins.size();
        int totalSubsets = 1 << n;

        // Precompute LCM and set sizes for all non-empty subsets
        vector<pair<long long, int>> subsets;
        for (int mask = 1; mask < totalSubsets; ++mask) {
            long long currentLcm = 1;
            int bits = 0;
            bool overflow = false;
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    bits++;
                    currentLcm = lcm(currentLcm, coins[i]);
                    if (currentLcm > high) {
                        overflow = true;
                        break;
                    }
                }
            }
            if (!overflow) {
                subsets.push_back({currentLcm, bits});
            }
        }

        // Binary search for the kth smallest amount
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = 0;

            for (const auto& [currLcm, bits] : subsets) {
                if (currLcm <= mid) {
                    if (bits % 2 == 1) {
                        count += mid / currLcm;
                    } else {
                        count -= mid / currLcm;
                    }
                }
            }

            if (count >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};