class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void solve(vector<int> &nums , int ind , vector<int> &temp , set<vector<int>> &curr)
    {
        
        if(temp.size() > 1)
        {
            curr.insert(temp);
        }
        if(ind >=n)
            return ;
        
        if(nums[ind] >= temp.back())
        {
            temp.push_back(nums[ind]);
            solve(nums , ind+1 , temp,curr);
            temp.pop_back();
            
            solve(nums , ind+1 , temp , curr);
        }
        else
            solve(nums , ind+1 , temp , curr);
        
        return ;
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        n = nums.size();
        set<vector<int>> curr;

        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            temp.push_back(nums[i]);
            solve(nums , i+1 , temp , curr);
           
        }
         for(auto &it:curr)
        {
            ans.push_back(it);
        }
        
        return ans;
    }
};