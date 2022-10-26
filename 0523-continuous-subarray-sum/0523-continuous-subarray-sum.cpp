class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int,int> mpp;
        mpp.insert({0,0});
        int currSum = 0;
        for(int i=0;i<n;i++)
        {
            currSum += nums[i];
            
            if(mpp.find(currSum%k) == mpp.end())
                mpp[currSum % k] = i+1;
            else if(mpp[currSum%k] < i)
                return true;
        }
        
        return false;
    }
};