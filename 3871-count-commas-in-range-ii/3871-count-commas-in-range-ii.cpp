#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // One-argument version: total commas from 1..n
    long long countCommas(long long n) {
        if (n < 1000) return 0;
        long long res = 0;
        // thresholds: 10^3, 10^6, 10^9, 10^12, 10^15, 10^18
        const vector<long long> th = {
            1000LL,
            1000000LL,
            1000000000LL,
            1000000000000LL,
            1000000000000000LL,
            1000000000000000000LL
        };
        for (int i = 0; i < (int)th.size(); ++i) {
            long long start = th[i];
            if (n < start) break;
            long long end = (i + 1 < (int)th.size() ? th[i+1] - 1 : n);
            long long upper = min(n, end);
            res += (upper - start + 1) * (long long)(i + 1);
        }
        return res;
    }

    // Two-argument version: commas in [L, R]
    long long countCommas(int L, int R) {
        long long l = (long long)L;
        long long r = (long long)R;
        return countCommas(r) - countCommas(l - 1);
    }
};
