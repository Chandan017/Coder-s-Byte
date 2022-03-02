class Solution {
public:
    
    int get(vector<int> &nums , int ind , vector<int> &dp)
    {
        if(ind>=nums.size())
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int steal=nums[ind] + get(nums,ind+2 , dp);
        int notSteal=get(nums,ind+1 ,dp);
        
        return dp[ind]= max(steal , notSteal);
    }
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n,-1);
        return get(nums, 0 , dp);
    }
};