class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        set<string> st;
        
        for(auto it:dictionary)
            st.insert(it);
        
        string ans="";
        
        string temp="";
        
        bool flag=true;
        for(int i=0;i<sentence.length();i++)
        {
           if(i==sentence.length() || sentence[i]==' ')
           {
               temp="";
               flag=true;
           }
            else if(sentence[i]!=' ')
                temp+=sentence[i];
            
            
            if(st.find(temp)!=st.end() && flag)
            {
                ans+=sentence[i];
                flag=false;
            }
            else if(flag && i!=sentence.length())
                ans+=sentence[i];
        }
        
        
        
        return ans;
        
    }
};