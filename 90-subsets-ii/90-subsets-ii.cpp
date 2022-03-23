class Solution {
public:
    set<vector<int>> st;
    
    void getAll(vector<int> &nums , int ind , int n , vector<int> &temp)
    {
        if(ind==n)
        {
            st.insert(temp);
            return;
        }
        temp.push_back(nums[ind]);
        getAll(nums , ind+1 , n , temp);
        temp.pop_back();
        getAll(nums , ind+1 , n , temp);
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        
        vector<int> temp;
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        
        getAll(nums , 0 , nums.size() , temp);
        
        for(auto &it:st)
            ans.push_back(it);
        return ans;
    }
};