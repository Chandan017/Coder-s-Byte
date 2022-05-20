class Solution {
public:
    
    vector<vector<int>> ans;
    
    void solve(vector<int> &nums , int target ,int ind, vector<int> &temp)
    {
        
        if(target==0)
        {
            ans.push_back(temp);
            return ;
        }
        
        for(; ind < nums.size();ind++)
        {
            if(target - nums[ind] >=0)
            {
                temp.push_back(nums[ind]);
                solve(nums , target - nums[ind] , ind , temp);
                temp.pop_back();
            }
        }
        
        return ;
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> temp;
        
        solve(candidates , target ,0, temp);
        
        return ans;
        
    }
};