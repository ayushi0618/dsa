class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sum1 = 0, sum2 = 0;
        int q1 = 0, q2 = 0;

        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                q1++;
            } else {
                sum1 += num[i] - '0';
            }
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                q2++;
            } else {
                sum2 += num[i] - '0';
            }
        }

        // If total question marks is odd, Alice wins.
        if ((q1 + q2) % 2 != 0) {
            return true;
        }

        // If total question marks is even, check if Bob can force equal sums.
        // Condition for Bob to win: 2 * (sum1 - sum2) + 9 * (q1 - q2) == 0
        return 2 * (sum1 - sum2) + 9 * (q1 - q2) != 0;
    }
};