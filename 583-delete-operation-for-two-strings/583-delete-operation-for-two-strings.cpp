class Solution {
public:
    int lcs(string &word1 , string &word2 , int ind1 , int ind2 , vector<vector<int>> &dp)
    {
        if(ind1==0 || ind2==0)
            return 0;
        if(dp[ind1][ind2])
            return dp[ind1][ind2];
        
        if(word1[ind1-1] == word2[ind2-1])
            return dp[ind1][ind2] = 1 + lcs(word1 , word2 , ind1-1 , ind2-1 , dp);
        else
            return dp[ind1][ind2] = max(lcs(word1 , word2 , ind1-1 , ind2 , dp) , lcs(word1 , word2 , ind1 , ind2-1 , dp));
    }
    
    int minDistance(string word1, string word2) {
        
        int n = word1.length() , m = word2.length();
        vector<vector<int>> dp(n+1 , vector<int> (m+1));
        
        int longestCommonSubsequence = lcs(word1 , word2 , n , m , dp);
        
        int totalLength = n+m;
        
        longestCommonSubsequence = totalLength - (2*longestCommonSubsequence);
        
        
        return longestCommonSubsequence;
        
               
    }
};