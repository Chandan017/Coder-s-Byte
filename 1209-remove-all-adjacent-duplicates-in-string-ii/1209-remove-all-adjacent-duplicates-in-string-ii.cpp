class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>> st;
        
        for(auto &it:s)
        {
            if(st.size() > 0 && st.top().first==it)
            {
                int times = st.top().second;
                st.pop();
                st.push({it , times+1});
            }
            else
                st.push({it , 1});
            
            if(st.top().second == k)
                st.pop();
        }
        
        string ans = "";
        
        while(st.size())
        {
            int times = st.top().second;
            char val = st.top().first;
            while(times--)
            {
                ans += val;
            }
            st.pop();
        }
        
        reverse(ans.begin() , ans.end());
        
        return ans;
    }
};