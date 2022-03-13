class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        for(auto &it:s)
        {
            if(it=='(' || it=='{' || it=='[')
                st.push(it);
            
            else if(!st.empty())
            {
                if(it==')' && st.top()=='(')
                    st.pop();
                else if(it=='}' && st.top()=='{')
                    st.pop();
                else if(it==']' && st.top()=='[')
                    st.pop();
                else
                    return false;
                
            }
            else
                return false;
        }
        
        
        cout<<st.size()<<endl;
        if(st.size()==0)
            return true;
        else
            return false;
        
    }
};