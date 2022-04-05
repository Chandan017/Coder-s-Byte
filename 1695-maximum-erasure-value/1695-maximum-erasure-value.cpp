class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        
        int maxSum = 0 , n = nums.size();
        unordered_map<int,int> mpp;
        int currSum=0;
        int l=0;
        for(int i=0;i<n;i++)
        {
            if(mpp.find(nums[i])!=mpp.end())
            {
                int ind=mpp[nums[i]];
                while(l<=ind)
                {
                    mpp.erase(nums[l]);
                    currSum -= nums[l];
                    l++;
                }
                
            }
            
            mpp[nums[i]]=i;
            currSum += nums[i];
            
            maxSum = max(currSum , maxSum);
        }
        return maxSum;
        
    }
};