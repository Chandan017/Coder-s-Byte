class Solution {
public:
    
    
    int solve(vector<int> &prices , int ind , int fee , bool canBuy , vector<vector<int>> &dp)
    {
        if(ind >= prices.size())
            return 0;
        
        
        if(dp[ind][canBuy] != -1)
            return dp[ind][canBuy];
        
        int hold = solve(prices , ind+1 , fee , canBuy , dp);
        
        int buy = 0 , sell = 0;
        if(canBuy)
        {
            buy = -prices[ind] + solve(prices , ind+1 , fee , false , dp);
        }
        else
        {
            sell = prices[ind] + solve(prices , ind+1 , fee , true , dp) - fee;
        }
        
        
        dp[ind][canBuy] = max({buy , sell , hold});
        
        return dp[ind][canBuy];
    }
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n , vector<int> (2 , -1));
        
        
        int res = solve(prices , 0 , fee , true , dp);
        
        
        return res;
    }
};