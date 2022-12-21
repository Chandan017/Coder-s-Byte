class Solution {
public:
    int solve(vector<int> &nums , int ind , vector<int> &dp)
    {
        if(ind >=nums.size())
            return 0;
        if(ind == nums.size()-1)
            return nums[ind];
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int oneStep = solve(nums , ind+1 , dp);
        int twoStep = solve(nums , ind+2 , dp);
        
        dp[ind] = nums[ind] + min(oneStep , twoStep);
        return dp[ind];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int> dp(cost.size(),-1);
        
        int zero = solve(cost , 0 , dp);
        int one = solve(cost , 1 , dp);
        
        return min(zero , one);
    }
};