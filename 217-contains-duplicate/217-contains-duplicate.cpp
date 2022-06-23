class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        map<int,int> mpp;
        
        for(auto it:nums)
            mpp[it]++;
        
        int n = nums.size();
        
        if(mpp.size()==n)
            return false;
        else
            return true;
        
    }
};