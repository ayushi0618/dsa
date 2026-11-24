#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int ans = 0;
        const long long MAX_LG = 2520LL * 10LL; // max lcm(1..10) * max val(10)

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; ++j) {
                long long x = nums[j];
                prod *= x;
                g = (g == 0) ? x : std::gcd(g, x);
                l = std::lcm(l, x);

                if (prod == l * g) {
                    ans = max(ans, j - i + 1);
                }

                // prod only grows; once it exceeds max possible l * g, no future j can match
                if (prod > MAX_LG) {
                    break;
                }
            }
        }

        return ans;
    }
};