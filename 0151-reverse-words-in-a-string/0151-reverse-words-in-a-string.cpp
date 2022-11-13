class Solution {
public:
    string reverseWords(string s) {
        
        string curr = "" , res = "";
        
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i] == ' ')
            {
                if(curr.length())
                {
                    reverse(curr.begin() , curr.end());
                    res += curr;
                    res += " ";
                }
                
                
                curr = "";
            }
            else
                curr += s[i];
        }
        
        
        if(curr.length())
        {
            reverse(curr.begin(),curr.end());
            res += curr;
        }
        else
            res.pop_back();
        
        
        
        return res;
        
        
    }
};