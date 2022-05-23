class Solution {
public:
    
    int solve(vector<string> &strs , int maxZero , int maxOne , int ind , vector<vector<vector<int>>> &dp)
    {
        if(ind == strs.size())
        {
            return 0;
        }
        
        if(dp[ind][maxZero][maxOne] != -1)
            return dp[ind][maxZero][maxOne];
        
        int zeroCnt = count(strs[ind].begin() , strs[ind].end() , '0');
        int oneCnt = strs[ind].length() - zeroCnt;
        
        if(maxZero-zeroCnt>=0 && maxOne-oneCnt>=0)
        {
            int takeIt = 1 + solve(strs , maxZero - zeroCnt , maxOne-oneCnt , ind+1,dp);
            int notTakeIt = solve(strs , maxZero , maxOne , ind+1 , dp);
            
            return dp[ind][maxZero][maxOne] = max(takeIt , notTakeIt);
        }
        
        else
            return dp[ind][maxZero][maxOne] = solve(strs , maxZero , maxOne , ind+1 , dp);
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int len = strs.size();
        
        vector<vector<vector<int>>> dp(len+1 ,vector<vector<int>> (m+1 , vector<int>(n+1 , -1)) );
        int maxLen = solve(strs , m , n , 0 , dp);
        
        return maxLen;
    }
};