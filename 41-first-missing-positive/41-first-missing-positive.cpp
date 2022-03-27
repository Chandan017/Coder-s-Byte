class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        set<int> st;
        long maxi=0;
        for(auto it:nums)
        {
            if(it >0)
                st.insert(it);
            
            if(it > maxi)
                maxi=it;
        }
        
        int i=1;
        long ans=maxi+1;
        while(i<=maxi)
        {
            if(st.find(i)==st.end())
            {
                ans=i;
                break;
            }
            i++;
        }
        
        return ans;
        
    }
};