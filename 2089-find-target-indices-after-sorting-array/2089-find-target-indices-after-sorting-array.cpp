class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lesser = 0;
        int count = 0;
        
        // Count numbers less than target and equal to target
        for (int x : nums) {
            if (x < target) {
                lesser++;
            } else if (x == target) {
                count++;
            }
        }
        
        // Build the resulting index list
        vector<int> ans;
        for (int i = 0; i < count; i++) {
            ans.push_back(lesser + i);
        }
        
        return ans;
    }
};