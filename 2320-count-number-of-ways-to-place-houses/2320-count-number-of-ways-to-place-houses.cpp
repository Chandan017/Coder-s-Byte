class Solution {
public:
    int mod = 1e9+7;
    
    int getCnt(int n , vector<int> &dp)
    {
        if(n<=0)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        int place = getCnt(n-2 , dp);
        int notPlace = getCnt(n-1 , dp);
        
        dp[n] = (place + notPlace)%mod;
        
        return dp[n];
    }
    int countHousePlacements(int n) {
        
        vector<int> dp(n+1 , -1);
        
        long currCnt = getCnt(n , dp);
        
        int res = (currCnt%mod*currCnt%mod)%mod;
        
        return res;
        
    }
};