class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector<int> res = nums;
        sort(nums.begin() , nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            int cnt = lower_bound(nums.begin() , nums.end() , res[i]) - nums.begin();
            
            res[i] = cnt;
        }
        
        
        return res;
        
    }
};