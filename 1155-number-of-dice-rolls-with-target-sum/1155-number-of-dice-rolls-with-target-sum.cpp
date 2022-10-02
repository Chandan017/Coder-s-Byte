class Solution {
public:
    vector<vector<int>> dp;
    int mod = 1e9+7;
    
    long solve(int n , int k , int target)
    {
        if(n==0 && target==0)
            return 1;
        
        if(n<0 || target<=0)
            return 0;
        if(dp[n][target] != -1)
            return dp[n][target];
        
        int total = 0;
        
        for(int i=1;i<=k;i++)
        {
            total += solve(n-1 , k , target-i);
            total %= mod;
        }
        
        return dp[n][target] = total;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        
        dp.resize(n+1 , vector<int> (target+1 , -1));
        long res = solve(n , k , target);
        res %= mod;
        return res;
    }
};