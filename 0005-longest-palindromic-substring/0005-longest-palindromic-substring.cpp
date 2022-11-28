class Solution {
public:
    
    bool isPalindrome(string &s)
    {
        int l = 0 , h = s.length()-1;
        
        while(l<h)
        {
            if(s[l] != s[h])
                return false;
            l++;
            h--;
        }
        
        return true;
    }
    
    string longestPalindrome(string s) {
        
        int n = s.length();
        
        string res = "";
        for(int i=0;i<n;i++)
        {
            string curr = "";
            
            for(int j=i;j<n;j++)
            {
                curr += s[j];
                
                if(curr.length() > res.length()  && isPalindrome(curr))
                    res = curr;
            }
        }
        
        return res;
        
    }
};