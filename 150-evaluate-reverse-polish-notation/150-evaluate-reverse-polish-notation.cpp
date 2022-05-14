class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<long> st;
        
        for(auto &it:tokens)
        {
            if(it.size()==1 && !isdigit(it[0]))
            {
                long a = st.top();
                st.pop();
                long b = st.top();
                st.pop();
                
                long res;
                if(it=="+")
                    res = a+b;
                else if(it=="-")
                    res = b-a;
                else if(it=="*")
                    res = a*b;
                else if(it=="/")
                    res = b/a;
                
                st.push(res);
            }
            else
                st.push(stoll(it));
        }
        
        return st.top();
        
    }
};