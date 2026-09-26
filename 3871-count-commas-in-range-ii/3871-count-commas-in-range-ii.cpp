class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        
        // Boundaries for numbers having 1, 2, 3, 4, 5 commas respectively
        // 10^3 = 1000, 10^6 = 1000000, 10^9 = 1000000000, etc.
        long long p = 1000;
        long long commas = 1;
        
        while (p <= n) {
            long long next_p = p * 1000;
            long long count = min(n, next_p - 1) - p + 1;
            totalCommas += count * commas;
            
            p = next_p;
            commas++;
        }
        
        return totalCommas;
    }
};