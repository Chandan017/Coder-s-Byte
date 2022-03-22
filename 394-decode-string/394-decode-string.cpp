class Solution {
public:
    string decodeString(string s) {
        
        stack<char> st;
        
        string ans="";
        
        for(int i=0;i<s.length();i++)
        {
            if(st.size()==0 && s[i]>='a' && s[i]<='z')
                ans+=s[i];
            else if(s[i]!=']')
                st.push(s[i]);
            else
            {
                string temp="";
                
                while(st.size() >0 && st.top()!='[')
                {
                    temp+=st.top();
                                 st.pop();
                }
                st.pop();
                string number="";
                while(st.size()>0 && st.top()>='0' && st.top()<='9')
                {
                    number+=st.top();
                    st.pop();
                }
                
                reverse(number.begin() , number.end());
                reverse(temp.begin() , temp.end());
                
                int times=stoi(number);
                string temp2=temp;
                temp="";
                while(times--)
                    temp+=temp2;
                
                if(st.size()==0)
                    ans+=temp;
                else
                {
                    for(auto it:temp)
                        st.push(it);
                }
            }
        }
        
        
        
        return ans;
        
    }
};