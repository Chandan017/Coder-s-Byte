class Solution {
public:
    string reverseWords(string s) {
        
        int n=s.length();
        
        string ans="";
        string temp="";
        
        int i=n-1;
        while(i>=0)
        {
            while(i>=0 && s[i]==' ')
                i--;
            
            while(i>=0 && s[i]!=' ')
            {
                temp+=s[i];
                i--;
            }
            
            if(temp!="")
            {
                reverse(temp.begin() , temp.end());
                
                ans+=temp;
                ans+=' ';
            }
            temp="";
        }
        ans.pop_back();
        return ans;
        
    }
};