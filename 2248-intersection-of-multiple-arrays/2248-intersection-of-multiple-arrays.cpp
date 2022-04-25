class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        
        map<int,int> mpp;
        int n = nums.size();
        vector<int> ans;
        
        
        for(auto it:nums)
        {
            for(auto ele:it)
                mpp[ele]++;
        }
        
        for(auto it:mpp)
        {
            if(it.second == n)
                ans.push_back(it.first);
        }
        
        return ans;
        
    }
};