class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int upperCnt = 0 , lowerCnt = 0 , n = word.length();
        
        for(auto it:word)
        {
            if(isupper(it))
                upperCnt++;
            else
                lowerCnt++;
        }
        
        if(upperCnt == n || lowerCnt == n)
            return true;
        
        if(upperCnt == 1 && lowerCnt == n-1 && isupper(word[0]))
            return true;
        
        return false;
        
    }
};