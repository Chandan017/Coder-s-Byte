class Solution {
public:
    int freqOfS[26]={0};
    int freqOfT[26]={0};
    void getFreq(string &s,int freq[])
    {
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a']++;
        }
    }
    bool isAnagram(string s, string t) {
        
        
        
        getFreq(s,freqOfS);
        getFreq(t,freqOfT);
        
        for(int i=0;i<26;i++)
        {
            if(freqOfS[i]!=freqOfT[i])
                return false;
        }
        
        return true;
        
    }
};