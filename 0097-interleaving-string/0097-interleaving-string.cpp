class Solution {
public:
    
    bool solve(string s1 , string s2 , string s3 , int i , int j , int ind , vector<vector<int>> &dp)
    {
        if(ind == s3.length() && i==s1.length() && j==s2.length())
        {
            return true;
        }
            
        
        if(i>=s1.length() && j>=s2.length())
            return false;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        bool takeS1 = false , takeS2 = false;
        
        if(i<s1.length() &&  s1[i] == s3[ind])
        {
            takeS1 = solve(s1 , s2 , s3 , i+1 , j , ind+1 , dp);
        }
        
        if(j<s2.length() && s2[j] == s3[ind])
        {
            takeS2 = solve(s1 , s2 , s3 , i , j+1 , ind+1 , dp);
        }
        
        
        return dp[i][j] = (takeS1 || takeS2);
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        vector<vector<int>> dp(s1.length()+1 , vector<int>(s2.length()+1 , -1 ));
        
        bool res = solve(s1 , s2 , s3 , 0 , 0 , 0 ,dp);
        
        return res;
        
    }
};