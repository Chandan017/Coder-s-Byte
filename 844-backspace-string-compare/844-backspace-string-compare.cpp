class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string st1 ="" ,st2="";
        
        for(auto it:s)
        {
            if(it=='#' && st1.length()>0)
                st1.pop_back();
            else if(it != '#')
                st1 += it;
        }
        
        for(auto it:t)
        {
            if(it=='#' && st2.length() >0)
                st2.pop_back();
            else if(it != '#')
                st2 += it;
        }
        
        
        return (st1 == st2);
    }
};