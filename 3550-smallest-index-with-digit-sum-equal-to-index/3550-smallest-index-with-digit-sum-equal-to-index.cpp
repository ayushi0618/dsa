class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int temp = nums[i];
            int digitSum = 0;
            
            // Handle 0 explicitly or let the loop handle it
            if (temp == 0) {
                digitSum = 0;
            } else {
                while (temp > 0) {
                    digitSum += temp % 10;
                    temp /= 10;
                }
            }
            
            if (digitSum == i) {
                return i;
            }
        }
        return -1;
    }
};