class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n=nums.size() , maxSum = 0 , currSum = 0 , left=0;
        
        vector<bool> vis(100001 , false);
        
        for(int i=0;i<n;i++)
        {
            
            while(vis[nums[i]])
            {
                vis[nums[left]] = false;
                currSum -= nums[left];
                left++;
            }
            
            currSum += nums[i];
            vis[nums[i]] = true;
            
            maxSum = max(maxSum , currSum);
        }
        
        return maxSum ;
        
    }
};