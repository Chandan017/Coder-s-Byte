class Solution {
public:
    
    int solve(vector<int> &prices , int ind , int cnt , bool canBuy , vector<vector<vector<int>>> &dp)
    {
        if(ind >= prices.size() || cnt==2)
            return 0;
        
        if(dp[ind][canBuy][cnt] != -1)
            return dp[ind][canBuy][cnt];
        
        int hold = solve(prices , ind+1 , cnt , canBuy , dp);
        int buy = 0 , sell = 0;
        
        if(canBuy)
        {
            buy = -prices[ind] + solve(prices , ind+1 , cnt , false , dp);
        }
        else
        {
            sell = prices[ind] + solve(prices , ind+1 , cnt+1 , true , dp);
        }
        
        
        return dp[ind][canBuy][cnt] = max({buy ,sell , hold});
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> temp(2 , vector<int>(2 , -1));
        vector<vector<vector<int>>> dp(n , temp);
        
        // int res = 0;
        
        int res = solve(prices , 0 , 0 , true , dp);
        
        return res;
    }
};