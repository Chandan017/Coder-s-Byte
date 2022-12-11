class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        
        
        int maxSum = -1 , n = nums.size();
        
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int currSum = nums[i] + nums[j];
                
                if(currSum < k)
                {
                    maxSum = max(maxSum ,currSum);
                }
            }
        }
        
        return maxSum;
        
    }
};