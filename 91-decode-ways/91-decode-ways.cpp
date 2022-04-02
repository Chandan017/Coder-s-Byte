class Solution {
public:
    int get(string &s , int ind , int n , vector<int> &dp)
    {
        if(ind < n && s[ind]=='0')
            return 0;
        
        if(ind >=n)
            return 1;
        
        if(dp[ind] !=-1)
            return dp[ind];
        
        int ways=0;
        
        ways+=get(s,ind+1 , n , dp);
        
        if(ind+1 < n && ((s[ind]=='1' && s[ind+1] < '10') ||( s[ind]=='2' && s[ind+1] <'7')))
            ways += get(s,ind+2 , n , dp);
           
        return  dp[ind] = ways;
    }
    int numDecodings(string s) {
        
        int n=s.length();
        vector<int> dp(n+1 , -1);
        return get(s,0,n , dp);
        
    }
};