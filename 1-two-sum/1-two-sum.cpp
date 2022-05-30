class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]] = i;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int rem = target - nums[i];
            
            if(mpp.find(rem) != mpp.end() && i != mpp[rem])
            {
                ans.push_back(i);
                ans.push_back(mpp[rem]);
                break;
            }
        }
        
        return ans;
        
    }
};