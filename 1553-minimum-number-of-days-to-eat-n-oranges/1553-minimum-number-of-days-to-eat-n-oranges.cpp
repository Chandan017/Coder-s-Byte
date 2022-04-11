class Solution {
public:
    
    unordered_map<int,int> dp;
    int getMin(int n)
    {
       if(n<=1)
           return n;
        
        if(dp.find(n) == dp.end())
        {
            dp[n] = 1 + min(n%2 + getMin(n/2) , n%3 + getMin(n/3));
        }
        
        return dp[n];
    }
    int minDays(int n) {
        
        int minDays = getMin(n);
        
        return minDays;
        
    }
};