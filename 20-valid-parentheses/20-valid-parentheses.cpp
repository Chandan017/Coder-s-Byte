class Solution {
public:
    bool isValid(string s) {
        
        
        int n=s.length();
        stack<char> st;
        
        for(auto &it:s)
        {
            if(it=='(' || it=='[' || it=='{')
                st.push(it);
            
            else if(st.size()>0 && it==')' && st.top()=='(')
                st.pop();
            else if(st.size()>0 && it==']' && st.top()=='[')
                st.pop();
            else if(st.size()>0 && it=='}' && st.top()=='{')
                st.pop();
            else
                return false;
        }
        
        return (st.size()==0);
        
    }
};