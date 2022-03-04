class Solution {
public:
    bool wordPattern(string pattern, string s) {
               
        s+=" ";
        vector<string> cnt(26,"-1");
        string x="";
        int ind=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
                x+=s[i];
            else
            {
               if(ind<pattern.size())
               {
                    if(cnt[pattern[ind]-'a']=="-1")
                {
                    cnt[pattern[ind]-'a']=x;
                    
                }
                else if(cnt[pattern[ind]-'a']!=x)
                    return false;
               }
                x="";
                ind++;
            }
        }
        
        if(ind!=pattern.size())
            return false;
        
        unordered_set<string> str;
       
        for(auto it:cnt)
        {
            if(it!="-1")
            {
                if(str.find(it)==str.end())
                str.insert(it);
            else 
                return false;
            }
        }
        
        
     
        return true;
        
    }
};