class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        int minPrice = prices[0] , maxProfit = 0 ;
        
        for(auto it:prices)
        {
            int currProfit = it - minPrice;
            maxProfit = max(maxProfit , currProfit);
            
            minPrice = min(minPrice , it);
        }
        
        return maxProfit;
        
    }
};