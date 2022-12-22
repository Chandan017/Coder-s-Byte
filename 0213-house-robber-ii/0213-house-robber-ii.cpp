class Solution {
public:
    int n;
    int dp[405];
    int solve(vector<int> &nums , int ind , int end)
    {
        if(ind >= end)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int take = nums[ind] + solve(nums , ind+2 , end );
        int notTake = solve(nums , ind+1 , end );
        
        dp[ind] = max(take , notTake);
        
        return dp[ind];
    }
    int rob(vector<int>& nums) {
        
        n = nums.size();
        
        if(n==1)
            return nums[0];
        memset(dp , -1 , sizeof(dp));
  
        int startFromZero = solve(nums , 0 , n-1);
        memset(dp , -1 , sizeof(dp));
        
        int startFromOne = solve(nums , 1 , n);
        
        return max(startFromZero , startFromOne);
        
        // return res;
        
    }
};