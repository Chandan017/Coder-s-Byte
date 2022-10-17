class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        unordered_set<int> st;
        
        int maxi = -1;
        
        for(auto it:nums)
        {
            if(it < 0)
            {               
                if(st.find(abs(it)) != st.end())
                    maxi = max(maxi , abs(it));
            }
            else if(st.find(-it) != st.end() && it > maxi)
                maxi = it;
           
            
            st.insert(it);
        }
        
       
        return maxi;
    }
};