class Solution {
public:
    int solve(vector<vector<int>> &costs , int ind , int prev , vector<vector<int>> &dp)
    {
        if(ind >= costs.size())
            return 0;
        
        if(prev != -1 && dp[ind][prev] != -1)
            return dp[ind][prev];
        
        int res = INT_MAX;
        for(int i=0;i<3;i++)
        {
            if(prev != i)
            {
                int curr = costs[ind][i] + solve(costs , ind+1 , i , dp);
                res = min(res , curr);
            }
        }
        
        if(prev != -1)
            dp[ind][prev] = res;
        
        return res;
    }
    int minCost(vector<vector<int>>& costs) {
        
        vector<vector<int>> dp(costs.size()+1 , vector<int>(3 , -1));
        int res = solve(costs , 0 , -1 , dp);
        return res;
        
    }
};