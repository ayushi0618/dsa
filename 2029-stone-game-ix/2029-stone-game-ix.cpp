class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> count(3, 0);
        
        // Count the frequency of each remainder
        for (int stone : stones) {
            count[stone % 3]++;
        }
        
        // If the count of 0s is even
        if (count[0] % 2 == 0) {
            // Alice wins if there is at least one 1 and at least one 2
            return count[1] > 0 && count[2] > 0;
        } 
        
        // If the count of 0s is odd
        // Alice wins if the difference between 1s and 2s is greater than 2
        return abs(count[1] - count[2]) > 2;
    }
};