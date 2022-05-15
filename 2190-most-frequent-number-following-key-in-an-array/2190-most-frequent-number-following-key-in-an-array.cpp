class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        
        map<int,int> mpp;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==key)
            {
                if(i+1 < nums.size())
                    mpp[nums[i+1]]++;
            }
        }
        
        int ans = INT_MAX;
        for(auto it:mpp)
        {
           if(ans==INT_MAX)
               ans = it.first;
            else
            {
                if(mpp[ans] < it.second)
                    ans = it.first;
            }
        }
        
        
        return ans;
        
    }
};