class Solution {
public:
    
    int get(string &a , string &b , int n , int m , vector<vector<int>> &dp)
    {
        if(n==0 || m==0)
            return 0;
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        if(a[n-1]==b[m-1])
            return dp[n][m] = 1 + get(a , b , n-1 , m-1 , dp);
        else
        {
            return dp[n][m] = max(get(a , b , n-1 , m , dp) , get(a,b,n,m-1 , dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.length() , m = text2.length();
        vector<vector<int>> dp(n+1 , vector<int> (m+1 , -1));
        int ans = get(text1 , text2 , n , m , dp);
        
        return ans;
        
    }
};