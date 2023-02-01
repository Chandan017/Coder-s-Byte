class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int leftSum = 0 , n = nums.size();
        int totalSum = accumulate(nums.begin() , nums.end() , 0);
        
        for(int i=0;i<n;i++)
        {
            int rightSum = totalSum - leftSum - nums[i];
            
            if(leftSum == rightSum)
                return i;
            
            leftSum += nums[i];
        }
        
        return -1;
        
    }
};