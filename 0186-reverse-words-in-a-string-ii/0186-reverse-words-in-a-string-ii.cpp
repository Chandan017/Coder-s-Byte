class Solution {
public:
    void reverseWords(vector<char>& s) {
        
        stack<char> st;
        vector<char> res;
        int n = s.size();
        
        for(int i=n-1;i>=0;i--)
        {
            if(s[i] == ' ')
            {
                while(st.size())
                {
                    res.push_back(st.top());
                    st.pop();
                }
                res.push_back(' ');
            }
            else
                st.push(s[i]);
        }
        
        
        while(st.size())
        {
            res.push_back(st.top());
            st.pop();
        }
        
        s = res;
        
        return ;
        
    }
};