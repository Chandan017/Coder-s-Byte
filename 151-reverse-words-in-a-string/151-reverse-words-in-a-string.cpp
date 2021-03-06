class Solution {
public:
    string reverseWords(string s) {
        
        stack<string>st;
        string ans="";
        int i=0;
        int n=s.length();
        while(i < n)
        {
            while(i < n && s[i]==' ')
                i++;
            
            while(i < n && s[i]!=' ')
            {
                ans+=s[i];
                i++;
            }
            
            if(ans!="")
                st.push(ans);
            ans="";
        }
        
       
        while(st.size()-1)
        {   
            ans+=st.top();
            st.pop();
            ans+=' ';
            
        }
        
        ans+=st.top();

        
        return ans;
        
    }
};