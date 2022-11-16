class Solution {
public:
    
    int solve(vector<int> &prices , int ind , bool canBuy , vector<vector<int>> &dp)
    {
        if(ind >= prices.size())
            return 0;
        
        if(dp[ind][canBuy] != -1)
            return dp[ind][canBuy];
        
        int cooldown = solve(prices , ind+1 , canBuy , dp);
        int buyOrSell = 0;
        
        if(canBuy)
        {
            buyOrSell = -prices[ind] + solve(prices , ind+1 , false , dp);
        }
        else
        {
            buyOrSell = prices[ind] + solve(prices , ind+2 , true , dp);
        }
        
        
        return dp[ind][canBuy] = max(cooldown , buyOrSell);
            
    }
    int maxProfit(vector<int>& prices) {
        
        
        int n = prices.size();
        vector<vector<int>> dp(n , vector<int> (2 , -1));
        
        int res = solve(prices , 0 , true , dp);
        
        return res;
        
    }
};