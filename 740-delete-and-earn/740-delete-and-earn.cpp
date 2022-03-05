class Solution {
public:
    
    int get(vector<int> &nums , int i,vector<int> &dp)
    {
        if(i>=nums.size())
            return 0;
        
        
        if(dp[i]!=-1)
            return dp[i];
        
        int currVal=nums[i];
        int currSum=nums[i];
        int index=i+1;
        
        while(index < nums.size() && nums[index]==currVal)
        {
            currSum+=nums[index];
            index++;
        }
        
        while(index < nums.size() && nums[index]==currVal+1)
        {
            index++;
        }
        
        
        return dp[i]= max(currSum + get(nums,index,dp) , get(nums,i+1,dp));
    }
    int deleteAndEarn(vector<int>& nums) {
        
        
        vector<int> dp(nums.size() , -1);
        sort(nums.begin() , nums.end());
        
        return get(nums,0,dp);
        
        
    }
};