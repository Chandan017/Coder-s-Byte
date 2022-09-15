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
            if(mpp[nums[i]])
            {
                mpp[nums[i]]--;
                int doub = nums[i]*2;
                if(mpp.find(doub) != mpp.end() && mpp[doub])
                {
                    res.push_back(nums[i]);
                    mpp[doub]--;
                }
                else
                    return {};
            }
        }
        
        return res;
        
    }
};