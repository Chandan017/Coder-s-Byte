class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        int n = nums.size();
        
        if(n%2)
            return {};
        vector<int> res;
        map<int,int> mpp;
        
        for(int i=0;i<n;i++)
            mpp[nums[i]]++;
        
        for(int i=0;i<n;i++)
        {
            if(mpp[nums[i]])
            {
                mpp[nums[i]]--;
                bool flag = false;
                int doub = nums[i]*2;
                if(mpp.find(doub) != mpp.end() && mpp[doub])
                {
                    res.push_back(nums[i]);
                    mpp[doub]--;
                    flag = true;
                }
                
                if(!flag)
                    mpp[nums[i]]++;
            }
        }
        
        
        
        
        if(res.size() == (n/2))
            return res;
        
        return {};
        
    }
};