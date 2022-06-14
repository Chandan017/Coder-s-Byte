class Solution {
public:
    
    int lcs(string &word1 , string &word2 , int n , int m , vector<vector<int>> &dp)
    {
        if(n==0 || m==0)
            return 0;
        
        if(dp[n][m])
            return dp[n][m];
        if(word1[n-1] == word2[m-1])
            return dp[n][m] = 1 + lcs(word1 , word2 , n-1 , m-1 , dp);
        return dp[n][m] = max(lcs(word1 , word2 , n-1 , m , dp) , lcs(word1 , word2 , n , m-1 , dp));
    }
    
    int minDistance(string word1, string word2) {
        
        if(word1 == word2)
            return 0;
        int n = word1.length() , m = word2.length();
        vector<vector<int>> dp(n+1 , vector<int> (m+1));
        
        int longest_common_subSeq = lcs(word1 , word2 , n , m , dp);
        
        int deleted_cnt = n + m - (2 * longest_common_subSeq);
        
        return deleted_cnt;
        
    }
};