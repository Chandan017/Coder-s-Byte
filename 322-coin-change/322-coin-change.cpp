class Solution {
public:
    
    long dp[10001][13];
    long get(vector<int> &coins , int amount , int n)
    {
        
        if(amount == 0)
            return 0;
        
        if(n==0)
            return INT_MAX -1 ;
        
        if(dp[amount][n])
            return dp[amount][n];
            
      
        int cnt;
        
        if(coins[n-1] > amount)
            cnt = get(coins , amount , n-1);
        
        else
        {
            int takeIt = 1 + get(coins , amount - coins[n-1] , n);
            int notTakeIt = get(coins , amount , n-1);
            
            cnt = min(takeIt , notTakeIt);
        }
        
        return dp[amount][n] = cnt;
        
    }
    int coinChange(vector<int>& coins, int amount) {
     
        
        int ans = get(coins , amount , coins.size());
        
        if(ans == INT_MAX - 1)
            ans = -1;
        return ans;
    }
};