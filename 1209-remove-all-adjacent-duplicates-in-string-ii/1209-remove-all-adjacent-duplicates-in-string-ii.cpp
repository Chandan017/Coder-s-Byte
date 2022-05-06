class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>> st;
        
        for(auto it:s)
        {
            if(st.size() > 0 && st.top().first==it)
            {
                int times = st.top().second;
                if(times+1 == k)
                {
                    while(times--)
                        st.pop();
                    
                }
                else
                    st.push({it , times+1});
            }
            else
                st.push({it , 1});
        }
        
        string ans = "";
        
        while(st.size())
        {
            ans += (st.top().first);
            st.pop();
        }
        
        reverse(ans.begin() , ans.end());
        
        return ans;
    }
};