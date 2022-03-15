class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        
        stack<pair<char , int>> st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' )
            {
                st.push({s[i] , i});
            }
            
            else if(s[i]==')')
            {
                if(st.size()>0 && st.top().first=='(')
                    st.pop();
                else
                    st.push({s[i] , i});
            }
        }
        
        
        while(st.size())
        {
            int i=st.top().second;
            st.pop();
            s.erase(s.begin()+i);
        }
        
        return s;
        
    }
};