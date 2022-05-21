class Solution {
public:
    
    int solve(vector<int> &coins , int amount , int n , vector<vector<int>> &dp)
    {
        if(amount==0)
            return 0;
        
        if(n==0)
            return INT_MAX-1;
        
        int cnt ;
        
        if(dp[amount][n] != -1)
            return dp[amount][n];
        
        if(coins[n-1] > amount)
            return dp[amount][n] = solve(coins , amount , n-1 , dp);
        else
        {
            int takeIt = 1 + solve(coins , amount-coins[n-1] , n , dp);
            int notTakeIt = solve(coins , amount , n-1 , dp);
            
            cnt = min(takeIt , notTakeIt);
        }
        
        return dp[amount][n] = cnt;
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp(amount+1 , vector<int>(n+1 , -1));
        int cnt = solve(coins , amount , n , dp);
        
        if(cnt == INT_MAX - 1)
            cnt = -1;
       
        
        return cnt;
        
    }
};