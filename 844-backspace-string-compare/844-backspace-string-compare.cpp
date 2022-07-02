class Solution {
public:
    
    string getOriginal(string &s)
    {
        string res = "";
        
        for(auto it:s)
        {
            if(it=='#' && res.length() >0)
                res.pop_back();
            else if(it!='#')
                res += it;
        }
        
        return res;
    }
    bool backspaceCompare(string s, string t) {
        
        
        string s1 = getOriginal(s);
        string s2 = getOriginal(t);
        
        return (s1==s2);
        
    }
};