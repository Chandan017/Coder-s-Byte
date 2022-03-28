class Solution {
public:
    string reverseWords(string s) {
        
        stack<string> st;
        
        string temp="";
        
        int i=0 , n=s.length();
        while(i < n)
        {
            while(i<n && s[i]==' ')
                i++;
            
            while(i<n && s[i]!=' ')
            {
                temp+=s[i];
                i++;
            }
            
            if(temp!="")
                st.push(temp);
            temp="";
            
        }
        
        string ans="";
        
        while(st.size())
        {
            ans+=st.top();
            st.pop();
            ans+=' ';
        }
        
        ans.pop_back();
        return ans;
        
    }
};