class Solution {
public:
    
    int solve(vector<int> &prices , int ind , bool buy , vector<vector<int>> &dp)
    {
        if(ind >= prices.size())
            return 0;
        
        if(dp[ind][buy] != -1)
            return dp[ind][buy];
        
        int notTakeIt = solve(prices , ind+1 , buy , dp);
        int takeIt = 0;
        
        if(buy)
        {
            takeIt = -prices[ind] + solve(prices , ind+1 , false , dp);
        }
        else
        {
            takeIt = prices[ind] + solve(prices , ind+2 , true , dp);
        }
        
        
        return dp[ind][buy] =  max(takeIt , notTakeIt);
        
    }
    int maxProfit(vector<int>& prices) {
        
        
        vector<vector<int>> dp(prices.size() , vector<int>(2 , -1));
        
        
        int res = solve(prices , 0 , true , dp);
        
        return res;
        
    }
};