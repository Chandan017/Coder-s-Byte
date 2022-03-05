class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
        
        int sLen=s.length() , pLen=p.length();
        
        if(sLen < pLen)
            return ans;
        
        int freqP[26]={0};
        int freqS[26]={0};
        
        for(int i=0;i<pLen;i++)
        {
            freqP[p[i]-'a']++;
            freqS[s[i]-'a']++;
        }
        
        freqS[s[pLen-1]-'a']--;
        
        for(int i=0;i<sLen-pLen+1;i++)
        {
            
            freqS[s[i+pLen-1]-'a']++;
            bool flag=true;
            for(int i=0;i<26;i++)
            {
                if(freqP[i]!=freqS[i])
                {
                    flag=false;
                    break;
                }
            }
            
            if(flag)
                ans.push_back(i);
            
            freqS[s[i]-'a']--;
            
           
        }
        
        return ans;
    }
};