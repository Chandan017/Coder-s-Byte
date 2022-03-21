class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char> st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(st.size() >0 && st.top()==s[i])
                st.pop();
            else
                st.push(s[i]);
        }
        
        string ans="";
        
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
    }
};