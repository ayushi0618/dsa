class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int buy = prices[0];
        for (int i= 1;i < prices.size(); i++){
            if(prices[i]<buy ){
                buy = prices[i];
            }
            else{
                if(max_profit < prices[i]-buy){
                    max_profit = prices[i]-buy;
                }
            }
        }
        return max_profit;
    }
};