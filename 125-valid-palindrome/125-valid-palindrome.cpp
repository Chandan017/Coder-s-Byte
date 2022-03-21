class Solution {
public:
    
    bool isValid(char c)
    {
        return ((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'));
    }
    
    bool isPalindrome(string s) {
        
        string temp="";
        
        for(int i=0;i<s.length();i++)
        {
            if(isValid(s[i]))
            {
                if(isupper(s[i]))
                    s[i]=tolower(s[i]);
                temp+=s[i];
            }
        }
        
        cout<<temp<<endl;
        string dummy=temp;
        
        reverse(dummy.begin() , dummy.end());
        
        return (temp==dummy);
        
        
        
    }
};