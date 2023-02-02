class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int tLen = t.length() , sLen = s.length();
        
        if(sLen > tLen)
            return false;
        
        int i=0,j=0;
        
        while(i<tLen && j<sLen)
        {
            if(t[i] == s[j])
                j++;
            i++;
        }
        if(j == sLen)
            return true;
        return false;
        
    }
};