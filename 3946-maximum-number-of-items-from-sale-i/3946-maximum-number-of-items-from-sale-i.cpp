#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = static_cast<int>(items.size());
        int minPrice = INT_MAX;
        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; ++i) {
            int factor = items[i][0];
            int price = items[i][1];
            minPrice = min(minPrice, price);

            int freeCnt = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && items[j][0] % factor == 0) {
                    ++freeCnt;
                }
            }

            int gain = 1 + freeCnt;
            for (int b = budget; b >= price; --b) {
                dp[b] = max(dp[b], dp[b - price] + gain);
            }
        }

        int ans = 0;
        for (int b = 0; b <= budget; ++b) {
            int extraCopies = (budget - b) / minPrice;
            ans = max(ans, dp[b] + extraCopies);
        }

        return ans;
    }
};