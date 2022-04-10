class Solution {
public:
    
    
    bool check(vector<int> &stones , int currInd , int k , int n , vector<vector<int>> &dp)
    {
        if(currInd == n-1)
            return true;
        if(currInd >= n)
            return false;
        
        if(dp[currInd][k] != -1)
            return dp[currInd][k];
        
        
        bool ans = false;
        
        for(int i=-1;i<=1;i++)
        {
            int newK = k+i;
            
            if(newK >0)
            {
                int ind = lower_bound(stones.begin() , stones.end() , stones[currInd]+newK) - stones.begin();
                
                if(ind!= n && stones[ind]==stones[currInd]+newK)
                {
                    bool currAns = check(stones , ind , newK , n , dp);
                    
                    ans = ans || currAns;
                }
            }
        }
        
        return dp[currInd][k] = ans;
    }
    bool canCross(vector<int>& stones) {
        
        int n=stones.size();
        vector<vector<int>> dp(n+1 , vector<int> (n+1 ,-1));
        bool ans = check(stones , 0 , 0 , n , dp);
        
        return ans;
    }
};