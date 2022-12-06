class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        map<int,int> mpp;
        
        int right=0, n = nums.size();
        
        while(right<k-1)
        {
            mpp[nums[right]]++;
            right++;
        }
        

        int left = 0;
        vector<int> res;
    
        while(right<n)
        {
            mpp[nums[right]]++;
            
            auto curr = mpp.rbegin();
            
            res.push_back(curr->first);
            
            mpp[nums[left]]--;
            
            if(mpp[nums[left]] == 0)
            {
                mpp.erase(nums[left]);
            }
            
            left++;
            right++;
        }
        
        
        
        return res;
    }
};