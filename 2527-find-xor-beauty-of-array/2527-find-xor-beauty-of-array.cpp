class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        
        int res = 0;
        
        for(auto it:nums)
        {
            res ^= it;
        }
        
        return res;
        
    }
};