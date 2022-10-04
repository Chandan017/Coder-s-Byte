class Solution {
public:
    
    int solve(int amount , int ind , vector<int> &coins , vector<vector<int>> &dp)
    {
        if(ind >= coins.size() || amount < 0)
            return 0;
        
        if(amount == 0)
            return 1;
        
        if(dp[amount][ind] != -1)
            return dp[amount][ind];
        
        int ways = 0;
        for(int i=ind;i<coins.size();i++)
        {
            ways += solve(amount-coins[i] , i , coins , dp);
        }
        
        return dp[amount][ind] = ways;
    }
    
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>> dp(amount+1 , vector<int> (coins.size()+1 , -1));
        
        int ways = solve(amount , 0 , coins , dp);
        
        return ways;
        
    }
};