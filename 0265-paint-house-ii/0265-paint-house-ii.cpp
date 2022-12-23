class Solution {
public:
    
    int solve(vector<vector<int>> &costs , int ind , int prev , int k , vector<vector<int>> &dp)
    {
        if(ind >= costs.size())
            return 0;
        
        if(prev != -1 && dp[ind][prev] != -1)
            return dp[ind][prev];
        
        int res = INT_MAX;
        for(int i=0;i<k;i++)
        {
            if(prev != i)
            {
                int curr = costs[ind][i] + solve(costs , ind+1 , i , k , dp);
                res = min(res , curr);
            }
        }
        
        if(prev != -1)
            dp[ind][prev] = res;
        
        return res;
    }
    int minCostII(vector<vector<int>>& costs) {
        
        int n = costs.size() , k = costs[0].size();
        
        vector<vector<int>> dp(n+1 , vector<int>(k+1 , -1));
        int res = solve(costs , 0 , -1 , k , dp);
        return res;
        
    }
};