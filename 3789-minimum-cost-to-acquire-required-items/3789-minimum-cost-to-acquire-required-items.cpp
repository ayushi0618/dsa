class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long totalCost = 0;
        
        // 1. Satisfy the overlapping requirement using the cheaper option between (costBoth) and (cost1 + cost2)
        long long common = min((long long)need1, (long long)need2);
        long long combinedCost = min((long long)costBoth, (long long)cost1 + (long long)cost2);
        totalCost += common * combinedCost;
        
        need1 -= common;
        need2 -= common;
        
        // 2. Satisfy any remaining requirement for type 1
        if (need1 > 0) {
            long long singleCost1 = min((long long)cost1, (long long)costBoth);
            totalCost += (long long)need1 * singleCost1;
        }
        
        // 3. Satisfy any remaining requirement for type 2
        if (need2 > 0) {
            long long singleCost2 = min((long long)cost2, (long long)costBoth);
            totalCost += (long long)need2 * singleCost2;
        }
        
        return totalCost;
    }
};