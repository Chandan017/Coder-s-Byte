class Solution {
public:
    int n;
    
    int solve(vector<int> &nums , int ind , vector<int> &dp)
    {
        if(ind >= n)
            return 0;
        if(dp[ind] != -1)
            return dp[ind];
        
        int rob = nums[ind] + solve(nums , ind+2 , dp);
        int notRob = solve(nums , ind+1 , dp);
        
        return dp[ind] = max(rob , notRob);
        
    }
    int rob(vector<int>& nums) {
        
        n = nums.size();
        vector<int> dp(n , -1);
        
        int res = solve(nums , 0 , dp);
        
        return res;
        
    }
};