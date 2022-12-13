class Solution {
public:
    int mod = 1e9+7;
    
    int getCnt(int ind , int n , vector<int> &dp)
    {
        if(ind>=n)
            return 1;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int place = getCnt(ind+2 , n , dp);
        int notPlace = getCnt(ind+1 , n , dp);
        
        dp[ind] = (place + notPlace)%mod;
        
        return dp[ind];
    }
    int countHousePlacements(int n) {
        
        vector<int> dp(n+1 , -1);
        
        long currCnt = getCnt(0 , n , dp);
        
        int res = (currCnt%mod*currCnt%mod)%mod;
        
        return res;
        
    }
};