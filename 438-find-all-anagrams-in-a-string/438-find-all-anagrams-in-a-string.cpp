class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
        
        int sLen=s.length() , pLen=p.length();
        
        int freqP[26]={0};
        for(int i=0;i<pLen;i++)
        {
            freqP[p[i]-'a']++;
        }
        
        for(int i=0;i<sLen-pLen+1;i++)
        {
            int freqS[26]={0};
            for(int j=i;j<i+pLen;j++)
            {
                freqS[s[j]-'a']++;
            }
            
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
           
        }
        
        return ans;
    }
};