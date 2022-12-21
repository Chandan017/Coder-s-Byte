class Solution {
public:
    int mod = 1e9+7;
    int solve(int s , int e , int rem , vector<vector<int>> &dp)
    {
        if(s==e && rem==0)
            return 1;
        if(rem==0)
            return 0;
        
        if(dp[s+1001][rem] != -1)
            return dp[s+1001][rem];
        
        int ways = (solve(s+1 , e , rem-1,dp)%mod + solve(s-1 , e , rem-1,dp)%mod)%mod;
        
        dp[s+1001][rem] = ways;
        
        return ways;
    }
    
    
    int numberOfWays(int startPos, int endPos, int k) {
        
        vector<vector<int>> dp(3001, vector<int>(k+1 , -1));
        
        int res = solve(startPos , endPos , k , dp);
        
        return res;
        
    }
};