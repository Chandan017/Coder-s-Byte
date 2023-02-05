class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int pLen = p.length();
        vector<int> a(26,0) , b(26,0);
        
        for(auto it:p)
            a[it-'a']++;
        
        vector<int> res;
        
        for(int i=0;i<s.length();i++)
        {
            b[s[i]-'a']++;
            
            if(i >= pLen-1)
            {
                if(a == b)
                    res.push_back(i-pLen+1);
                
                b[s[i-pLen+1]-'a']--;
            }
        }
        
        return res;
        
    }
};