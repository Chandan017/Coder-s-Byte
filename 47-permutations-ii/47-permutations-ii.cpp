class Solution {
public:
    
    vector<vector<int>> ans;
    set<vector<int>> s;
    void get(vector<int> &nums,int i, int n)
    {
        if(i==n)
        {
            s.insert(nums);
            return ;
        }
        
        for(int j=i;j<=n;j++)
        {
            swap(nums[i] , nums[j]);
            
            get(nums,i+1,n);
            
            swap(nums[i] , nums[j]);
            
           
        }
        
        return ;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        int n=nums.size()-1;
        
        get(nums,0,n);
        
        for(auto &it:s)
            ans.push_back(it);
        return ans;
    }
};