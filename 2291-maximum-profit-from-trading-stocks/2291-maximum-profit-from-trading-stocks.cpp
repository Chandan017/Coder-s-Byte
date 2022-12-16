class Solution {
public:
    int solve(vector<int> &nums , vector<int> &future , int budget , int ind , vector<vector<int>> &dp)
    {
        if(ind >= nums.size() || budget < 0)
            return 0;
        
        if(dp[ind][budget] != -1)
            return dp[ind][budget];
        
        int take = 0;
        if(nums[ind] <= budget && future[ind] > nums[ind])
            take = future[ind] - nums[ind] + solve(nums , future , budget-nums[ind] , ind+1 , dp);
        
        int notTake = solve(nums , future , budget , ind+1 , dp);
        
        dp[ind][budget] = max(take , notTake);
        return dp[ind][budget];
    }
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        
        int n = present.size();
        vector<vector<int>> dp(n+1 , vector<int> (1001 , -1));
        int res = solve(present , future , budget , 0 , dp);
        
        return res;
        
    }
};