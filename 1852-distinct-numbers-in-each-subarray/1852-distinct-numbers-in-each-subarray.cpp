class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        
        vector<int> res;
        int n = nums.size() , prev = 0;
        map<int,int> mpp;
        for(int i=0;i<n;i++)
        {
            
            mpp[nums[i]]++;
            if(i >= k-1)
            {
                res.push_back(mpp.size());
                mpp[nums[prev]]--;
                if(mpp[nums[prev]] == 0)
                    mpp.erase(nums[prev]);
                prev++;
            }
            
            
        }
        
        
        return res;
        
    }
};