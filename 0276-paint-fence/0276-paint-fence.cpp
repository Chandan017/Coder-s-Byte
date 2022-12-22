class Solution {
public:
    int solve(int n , int k , vector<int> &dp)
    {
        if(n==1)
            return k;
        if(n == 2)
            return k*k;
        
        if(dp[n] != -1)
            return dp[n];
        
       int ans = (k-1)*solve(n-1 , k , dp) + (k-1)*solve(n-2 , k , dp);
    
        dp[n] = ans;
        return ans;
        
    }
    int numWays(int n, int k) {
        
        vector<int> dp(n+1 , -1);
        int res = solve(n , k , dp);
        
        return res;
    }
};