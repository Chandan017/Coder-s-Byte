class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();
        long sum = accumulate(nums.begin() , nums.end() , 0);
        
        if(sum < x)
            return -1;
        
        int left = 0 , right = 0 , ans = INT_MAX;
        
        long runningSum = 0;
        
        while(right < n)
        {
            runningSum += nums[right];
            while(runningSum > (sum-x) && left<n)
            {
                runningSum -= nums[left];
                left++;
            }
        
            
            if(runningSum == (sum-x))
            {
                ans = min(ans , n-(right-left+1));
            }
            
            right++;
        }
        
        
        
        if(ans==INT_MAX)
            return -1;
        return ans;
        
        
        
    }
};