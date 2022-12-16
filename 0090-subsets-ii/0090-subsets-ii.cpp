class Solution {
public:
    
    set<vector<int>> st;
    
    void solve(vector<int> &nums , int ind , vector<int> &curr)
    {
        if(ind >= nums.size())
        {
            st.insert(curr);
            return ;
        }
        
        curr.push_back(nums[ind]);
        solve(nums , ind+1 , curr);
        curr.pop_back();
        
        solve(nums , ind+1 , curr);
        
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        vector<int> curr;
        solve(nums , 0 , curr);
        
        vector<vector<int>> res;
        
        for(auto it:st)
            res.push_back(it);
        
        return res;
    }
};