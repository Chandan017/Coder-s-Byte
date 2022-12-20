class Solution {
public:
    int solve(vector<int> &nums , int target , vector<int> &dp)
    {
        if(target == 0)
            return 1;
        if(dp[target] != -1)
            return dp[target];
        
        int cnt = 0;
        for(auto it:nums)
        {
            if(target - it >=0)
            {
                cnt += solve(nums , target-it , dp);
            }
        }
        
        dp[target] = cnt;
        
        return cnt;
    }
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> dp(target+1 , -1);
        int res = solve(nums , target , dp);
        
        return res;
        
    }
};