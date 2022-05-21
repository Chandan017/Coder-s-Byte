class Solution {
public:
    
    int dp[10001][13];
    int solve(vector<int> &coins , int amount , int n)
    {
        if(amount==0)
            return 0;
        
        if(n==0)
            return INT_MAX-1;
        
        int cnt ;
        
        if(dp[amount][n])
            return dp[amount][n];
        
        if(coins[n-1] > amount)
            return dp[amount][n] = solve(coins , amount , n-1 );
        else
        {
            int takeIt = 1 + solve(coins , amount-coins[n-1] , n);
            int notTakeIt = solve(coins , amount , n-1);
            
            cnt = min(takeIt , notTakeIt);
        }
        
        return dp[amount][n] = cnt;
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        int cnt = solve(coins , amount , n);
        
        if(cnt == INT_MAX - 1)
            cnt = -1;
       
        
        return cnt;
        
    }
};