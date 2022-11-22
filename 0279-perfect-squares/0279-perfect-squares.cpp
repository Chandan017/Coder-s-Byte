class Solution {
public:
    vector<int> dp;
    int solve(int n)
    {
        if(n==0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        int mini = 1e5;
        for(int i=1;i<=sqrt(n);i++)
        {
            int curr = 1 + solve(n-(i*i));
            
            mini = min(mini , curr);
        }
        
        return dp[n] = mini;
    }
    
    
    int numSquares(int n) {
        
        dp.resize(n+1 , -1);
        int minCnt = solve(n);
        return minCnt;
        
    }
};