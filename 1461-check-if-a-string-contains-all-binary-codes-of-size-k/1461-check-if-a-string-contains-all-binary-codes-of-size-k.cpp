class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        int totalCombinations = 1<<k;
        int allOne = totalCombinations - 1;
        vector<bool> got(totalCombinations , false);
        
        int hashVal = 0;
        for(int i=0;i<s.length();i++)
        {
            hashVal = (hashVal << 1) & allOne;
            hashVal = hashVal | (s[i]-'0');
            
            if(i >= k-1 && !got[hashVal])
            {
                got[hashVal] = true;
                totalCombinations--;
                
            }
            
            if(totalCombinations == 0)
                return true;
        }
        
        return false;
        
    }
};