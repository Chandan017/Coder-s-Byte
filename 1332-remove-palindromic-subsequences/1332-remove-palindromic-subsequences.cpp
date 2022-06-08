class Solution {
public:
    int removePalindromeSub(string s) {
        
        string temp = s;
        reverse(s.begin() , s.end());
        
        if(temp == s)
            return 1;
        return 2;
        
    }
};