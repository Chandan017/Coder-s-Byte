class Solution {
public:
    
    vector<string> temp;
    void get(int n,string s)
    {
        if(s.length()==2*n)
        {
            temp.push_back(s);
            return ;
        }
        
        s+='(';
        get(n,s);
        s.pop_back();
        s+=')';
        get(n,s);
        return ;
    }
    
    bool check(string s)
    {
        stack<char> st;
        
        for(auto it:s)
        {
            if(it=='(')
                st.push(it);
            else if(it==')')
            {
                if(st.size() >0 && st.top()=='(')
                    st.pop();
                else
                    return false;
            }
                
        }
        
        if(st.size()==0)
            return true;
        return false;
    }
    vector<string> generateParenthesis(int n) {
        
        string s="";
        get(n,s);
        
        vector<string> ans;
        for(auto it:temp)
        {
            if(check(it))
                ans.push_back(it);
        }
        return ans;
    }
};