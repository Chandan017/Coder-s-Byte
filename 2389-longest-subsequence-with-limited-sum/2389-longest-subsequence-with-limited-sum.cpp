class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        sort(nums.begin() , nums.end());
        int n = nums.size();
        
        for(int i=1;i<n;i++)
        {
            nums[i] += nums[i-1];
        }
        
        // for(auto it:nums)
        //     cout<<it<<" ";
        // cout<<endl;
        vector<int> res;
        for(auto it:queries)
        {
            int ind = upper_bound(nums.begin() , nums.end() , it) - nums.begin();
            res.push_back(ind);
        }
        
        return res;
        
    }
};