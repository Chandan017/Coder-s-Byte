class Solution {
public:
    vector<vector<int>> ans;
    
    
    
    void get(vector<int> &nums , vector<int> temp , int ind)
    {
        if(ind==nums.size())
        {
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[ind]);
        
        get(nums , temp , ind+1);
        temp.pop_back();
        
        get(nums , temp , ind+1);
        
        return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        
        vector<int> temp;
        
        get(nums , temp ,0);
        
        return ans;
    }
};