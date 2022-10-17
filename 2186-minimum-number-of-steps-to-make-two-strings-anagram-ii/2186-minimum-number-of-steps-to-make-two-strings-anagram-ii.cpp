class Solution {
public:
    int minSteps(string s, string t) {
        
        vector<int> freq(26,0) ;
        
        for(auto c:s)
        {
            freq[c-'a']++;
        }
        
        int minCnt = 0;
        
        for(auto c:t)
        {
            if(freq[c-'a'] > 0)
                freq[c-'a']--;
            else
                minCnt++;
        }
        
        for(int i=0;i<26;i++)
        {
            minCnt += freq[i];
        }
        
        return minCnt;
        
    }
};