class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        
        int mini = nums[0] , res = -1;
        
        for(auto it:nums)
        {
            if(it > mini)
            {
                res = max(res , (it-mini));
            }
            
            mini = min(mini , it);
        }
        
        return res;
        
    }
};