#include <vector>
#include <array>
using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        array<int,10> freq{};
        for (int d : digits) ++freq[d];

        int ans = 0;
        for (int h = 1; h <= 9; ++h) {           // hundreds digit cannot be 0
            for (int t = 0; t <= 9; ++t) {       // tens digit
                for (int u = 0; u <= 8; u += 2) { // units must be even
                    array<int,10> need{};
                    ++need[h];
                    ++need[t];
                    ++need[u];
                    bool ok = true;
                    for (int d = 0; d <= 9; ++d) {
                        if (need[d] > freq[d]) { ok = false; break; }
                    }
                    if (ok) ++ans;
                }
            }
        }
        return ans;
    }
};
