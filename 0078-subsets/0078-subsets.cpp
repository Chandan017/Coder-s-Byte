class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int> &nums , int ind , vector<int> &curr)
    {
        if(ind >= nums.size())
        {
            res.push_back(curr);
            return ;
        }
        
        curr.push_back(nums[ind]);
        solve(nums , ind+1 , curr);
        curr.pop_back();
        solve(nums , ind+1  , curr);
        return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        
        vector<int> curr;
        solve(nums , 0 , curr);
        
        return res;
    }
};