class Solution {
public:
    bool check(string &s)
    {
        int l = 0 , h = s.length()-1;
        
        while(l<h)
        {
            if(s[l]!=s[h])
                return false;
            l++;
            h--;
        }
        
        return true;
    }
    
    string longestPalindrome(string s) {
        
        int n = s.length();
        if(n<=1)
            return s;
        string res = "";
        for(int i=0;i<n-1;i++)
        {
            string temp = "";
            for(int j=i;j<n;j++)
            {
                temp += s[j];
                
                if(temp.length() > res.length())
                {
                    if(check(temp))
                        res = temp;
                }
            }
            
            if(res.length()==n)
                return res;
        }
        
        return res;
        
    }
};