class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int ,vector<int>,greater<int>> a;
        for(int num:nums){
            a.push(num);
            if(a.size()>k){
                a.pop();
            }
        }
        return a.top();
    }
};