class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        unordered_set<int> st;
        
        int maxi = -1;
        
        for(auto it:nums)
        {
            if(it < 0)
                st.insert(it);
        }
        
        for(auto it:nums)
        {
            if(it > 0 && st.find(-it) != st.end() && it > maxi)
                maxi = it;
          
        }
        
      
        return maxi;
    }
};