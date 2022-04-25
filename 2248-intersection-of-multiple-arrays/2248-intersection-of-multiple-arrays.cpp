class Solution {
public:
    
    vector<int> intersect(vector<int> &v1 , vector<int> &v2)
    {
        set<int> st1 ;
        vector<int> ans;
        
        for(auto it:v1)
            st1.insert(it);
        
        for(auto it:v2)
        {
            if(st1.find(it) != st1.end())
                ans.push_back(it);
        }
        
        
        return ans;
        
        
    }
    
    vector<int> intersection(vector<vector<int>>& nums) {
        
        int n = nums.size();
        
       
        
        vector<int> ans = nums[0];
        vector<int> v2 ;
        
        for(int i = 1;i<n;i++)
        {
            v2 = nums[i];
            
            ans = intersect(ans , v2);
        }
        
        sort(ans.begin() , ans.end());
        return ans;
        
    }
};