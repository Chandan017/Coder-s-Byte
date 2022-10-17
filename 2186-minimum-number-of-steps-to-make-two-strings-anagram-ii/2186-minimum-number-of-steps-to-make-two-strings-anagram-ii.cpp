class Solution {
public:
    int minSteps(string s, string t) {
        
        vector<int> freq1(26,0) , freq2(26,0);
        
        for(auto c:s)
        {
            freq1[c-'a']++;
        }
        
        for(auto c:t)
        {
            if(freq1[c-'a'] > 0)
                freq1[c-'a']--;
            else
                freq2[c-'a']++;
        }
        
        int minCnt = 0;
        
        for(int i=0;i<26;i++)
        {
            minCnt += freq1[i] + freq2[i];
        }
        
        return minCnt;
        
    }
};