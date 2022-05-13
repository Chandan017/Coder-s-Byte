class Solution {
public:
    int dp[10001][13];
    int get(vector<int> &coins , int n , int amount)
    {
        if(amount == 0)
            return 0;
        
        if(n==0)
            return INT_MAX -1;
        
        if(dp[amount][n])
            return dp[amount][n];
        
        int cnt;
        if(coins[n-1] > amount)
            cnt = get(coins , n-1 , amount);
        
        else
        {
            int takeIt = 1 + get(coins , n , amount - coins[n-1]);
            int notTakeIt = get(coins , n-1 , amount);
            
            cnt = min(takeIt , notTakeIt);
        }
        
        return dp[amount][n] = cnt;
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        int ans = get(coins , n , amount);
        
        if(ans == INT_MAX -1)
            ans = -1;
        
        return ans;
        
    }
};