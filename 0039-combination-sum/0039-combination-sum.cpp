class Solution {
public:
    
    vector<vector<int>> res;
    void solve(vector<int> &nums , int ind , int sum , vector<int> curr)
    {
        if(ind >= nums.size() || sum < 0)
            return ;
        
        if(sum == 0)
        {
            res.push_back(curr);
            return ;
        }
        
        for(int i=ind;i<nums.size();i++)
        {
            curr.push_back(nums[i]);
            solve(nums , i , sum - nums[i] , curr);
            curr.pop_back();
        }
        
        return ;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> curr;
        
        solve(candidates , 0 , target , curr);
        
        return res;
        
    }
};