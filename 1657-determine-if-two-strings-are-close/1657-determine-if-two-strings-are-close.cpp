class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        vector<int> freq1(26,0) , freq2(26,0);
        
        for(auto &c:word1)
        {
            freq1[c-'a']++;
        }
        
        for(auto &c:word2)
        {
            freq2[c-'a']++;
            
            if(freq1[c-'a']==0)
                return false;
        }
        
        unordered_map<int,int> cntMap;
        
        for(auto &it:freq1)
        {
            if(it > 0)
                cntMap[it]++;
        }
        
        for(auto &it:freq2)
        {
            if(it == 0)
                continue;
            if(cntMap.find(it) != cntMap.end() && cntMap[it] > 0)
                cntMap[it]--;
            else
                return false;
        }
        
        return true;
        
    }
};