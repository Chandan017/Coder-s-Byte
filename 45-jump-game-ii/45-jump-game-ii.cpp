class Solution {
public:
    
    long getMin(vector<int> &nums , int ind ,vector<int> &dp)
    {
        if(ind >= nums.size()-1)
            return 0;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        int mini = 10000000;
        
        for(int i=1;i<=nums[ind];i++)
        {
            int currJumps = 1 + getMin(nums , ind+i , dp);
            
            mini = min(mini ,currJumps);
        }
        return dp[ind] = mini;
    }
    
    int jump(vector<int>& nums) {
        
        int ind=0;
        int n=nums.size();
        vector<int> dp(n , -1);
        int minJumps = getMin(nums , ind , dp);
        return minJumps;
        
    }
};