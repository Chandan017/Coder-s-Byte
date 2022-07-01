class Solution {
public:
    
    
    int solve(int n , vector<int> &dp)
    {
        if(n==0)
            return 0;
        
        if(dp[n])
            return dp[n];
        
        int mini = INT_MAX;
        
        for(int i=1;i<=sqrt(n);i++)
        {
            int curr = 1 + solve(n-(i*i) , dp);
            
            mini = min(mini , curr);
        }
        
        return dp[n] = mini;
    }
    int numSquares(int n) {
        
        vector<int> dp(n+1);
        return solve(n , dp);
        
    }
};