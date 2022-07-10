class Solution {
public:
    int dp[10001];
    int solve(vector<int> &cost , int ind , int n)
    {
        if(ind>=n)
            return 0;
        
        if(dp[ind])
            return dp[ind];
        
        int oneStep = cost[ind] + solve(cost , ind+1 , n);
        int twoStep = cost[ind] + solve(cost , ind+2 , n);
        
        return dp[ind] =  min(oneStep , twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        int zeroInd = solve(cost , 0 , n);
        int oneInd = solve(cost ,1 , n);
        
        return min(oneInd , zeroInd);
        
    }
};