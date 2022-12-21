class Solution {
public:
    // long res = 0;
    int mod = 1e9+7;
    
    int solve(int low , int high , int zero , int one , long currLen , vector<int> &dp)
    {
        if(currLen > high)
            return 0;
        
        if(dp[currLen] != -1)
            return dp[currLen];
        
        
        
        int takeZero =  solve(low , high , zero , one , currLen+zero , dp);
        if(currLen+zero >= low && currLen+zero <= high)
            takeZero++;
        
        int takeOne = solve(low , high , zero , one , currLen+one , dp);
        if(currLen+one >= low && currLen+one <= high)
            takeOne++;
        
        dp[currLen] = (takeZero+takeOne)%mod;
        
        return dp[currLen];
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        
        vector<int> dp(high+1 , -1);
        
        int res = solve(low , high , zero , one , 0 , dp);
        
        res %= mod;
        return res;
    }
};