class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int currSum = 0;
        int maxSum = INT_MIN;
        
        for(int i=0;i<nums.size();i++)
        {
            currSum += nums[i];
            
            maxSum = max(maxSum , currSum);
            
            currSum = max(currSum , 0);
        }
        
        return maxSum;
    }
};