class Solution {
public:
    int solve(vector<int> &prices , int ind , int k , bool canBuy , vector<vector<vector<int>>> &dp)
    {
        if(ind>= prices.size() || k == 0)
            return 0;
        
        if(dp[ind][canBuy][k] != -1)
            return dp[ind][canBuy][k];
        
        int hold = solve(prices , ind+1 , k , canBuy , dp);
        
        int buy = 0 , sell = 0;
        
        if(canBuy)
        {
            buy = -prices[ind] + solve(prices , ind+1 , k , false , dp);
        }
        else
        {
            sell = prices[ind] + solve(prices , ind+1 , k-1 , true , dp);
        }
        
        
        dp[ind][canBuy][k] = max({buy , sell , hold});
        
        return dp[ind][canBuy][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        
        
        int n = prices.size();
        vector<vector<int>> temp(2 , vector<int>(k+1 , -1));
        vector<vector<vector<int>>> dp(n , temp);
        
        int res = solve(prices , 0 , k , true , dp );
        
        return res;
        
    }
};