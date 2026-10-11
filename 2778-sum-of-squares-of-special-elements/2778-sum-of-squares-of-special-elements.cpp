class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        std::vector<int> arr;
        int n= nums.size();
        int sum=0;
        for ( int i=1 ; i<=n; i++ ){
            if(n%i==0){
                arr.push_back(nums[i-1]*nums[i-1]);
                
            }
        }
        for (int j=0 ; j< arr.size(); j++){
            sum+=arr[j];
        }
        return sum ;
    }
};