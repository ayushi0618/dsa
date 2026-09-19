class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle boundary case of overflow
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign of the result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long to handle absolute value of INT_MIN safely
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        long long quotient = 0;

        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            // Double the divisor until it exceeds the remaining dividend
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            quotient += multiple;
        }

        return negative ? -quotient : quotient;
    }
};