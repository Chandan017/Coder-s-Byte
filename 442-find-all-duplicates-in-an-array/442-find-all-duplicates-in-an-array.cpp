class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> ans;
        
        for(auto it:nums)
        {
            int val = abs(it);
            
            if(nums[val-1] <0)
                ans.push_back(val);
            else
                nums[val -1] = 0-nums[val-1];
        }
        
        return ans;
        
    }
};