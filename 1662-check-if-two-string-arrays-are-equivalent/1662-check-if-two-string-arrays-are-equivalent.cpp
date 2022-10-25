class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        int i = 0 , j = 0 , n = 0 , m= 0;
        
        while(n<word1.size() && m<word2.size())
        {
            
            if(word1[n][i] != word2[m][j])
                return false;
            i++;
            j++;
            
            if(i==word1[n].length())
            {
                n++;
                i=0;
            }
            
            if(j==word2[m].length())
            {
                m++;
                j=0;
            }
        }
        
        
        if(n==word1.size() && m==word2.size())
            return true;
        
        return false;
    }
};