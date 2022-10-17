class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        map<char,int> freq;
        
        for(auto it:word1)
        {
            freq[it]++;
        }
        
        map<int,int> cnt;
        
        for(auto it:freq)
        {
            cnt[it.second]++;
        }
        
        map<char,int> freq2;
        
        for(auto it:word2)
        {
            freq2[it]++;
            if(freq.find(it) == freq.end())
                return false;
        }
        
        for(auto it:freq2)
        {
            if(cnt.find(it.second) != cnt.end() && cnt[it.second] > 0)
                cnt[it.second]--;
            else
                return false;
        }
        
        return true;
        
    }
};