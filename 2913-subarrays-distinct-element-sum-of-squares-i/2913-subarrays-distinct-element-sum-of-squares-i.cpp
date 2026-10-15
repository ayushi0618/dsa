class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        
        for (int l = 0; l < n; ++l) {
            unordered_set<int> distinctElements;
            for (int r = l; r < n; ++r) {
                distinctElements.insert(nums[r]);
                int count = distinctElements.size();
                totalSum += count * count;
            }
        }
        
        return totalSum;
    }
};