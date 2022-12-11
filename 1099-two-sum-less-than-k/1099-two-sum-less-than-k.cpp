class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        
        
        sort(nums.begin() , nums.end());
        
        int l = 0 , h = nums.size() -1 , maxSum = -1;
        
        while(l<h)
        {
            int currSum = nums[l] + nums[h];
            
            if(currSum < k)
            {
                maxSum = max(maxSum , currSum);
                l++;
            }
            else
                h--;
        }
        
        return maxSum;
        
    }
};