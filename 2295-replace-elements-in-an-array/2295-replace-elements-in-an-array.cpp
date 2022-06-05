class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        
        map<int,int> mpp;
        
        for(int i=0;i<nums.size();i++)
            mpp[nums[i]] = i;
        
        for(auto &it:operations)
        {
            int ind = mpp[it[0]];
            nums[ind] = it[1];
            mpp.erase(mpp.find(it[0]));
            mpp[it[1]] = ind;
        }
        
        return nums;
        
    }
};