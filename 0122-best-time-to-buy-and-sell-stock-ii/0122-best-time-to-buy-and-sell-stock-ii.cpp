class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        int totalProfit = 0;
        
        for(int i=0;i<n-1;i++)
        {
            if(prices[i] < prices[i+1])
            {
                int currProfit = prices[i+1] - prices[i];
                
                totalProfit += currProfit;
            }
        }
        
        return totalProfit;
        
    }
};