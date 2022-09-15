class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n%2)
            return {};
        
        sort(nums.begin() , nums.end());
        vector<int> res;
        unordered_map<int,int> mpp;
        
        for(int i=0;i<n;i++)
            mpp[nums[i]]++;
        
        for(int i=0;i<n;i++)
        {
            if(mpp[nums[i]] == 0)
                continue;
            int doub = nums[i]*2;
            if(mpp[doub] == 0)
                return {};
            mpp[doub]--;
            mpp[nums[i]]--;
            res.push_back(nums[i]);
        }
        
        return res;
        
    }
};