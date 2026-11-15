class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long oddCount = 0, evenCount = 1; // evenCount = 1 accounts for the initial prefix sum of 0
        long long currentSum = 0;
        long long totalSubarrays = 0;
        long long MOD = 1e9 + 7;

        for (int num : arr) {
            currentSum += num;
            
            if (currentSum % 2 != 0) {
                totalSubarrays = (totalSubarrays + evenCount) % MOD;
                oddCount++;
            } else {
                totalSubarrays = (totalSubarrays + oddCount) % MOD;
                evenCount++;
            }
        }

        return totalSubarrays;
    }
};