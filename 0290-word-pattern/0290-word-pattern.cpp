class Solution {
public:
    bool wordPattern(string pattern, string s) {
               
        s+=" ";
        vector<string> str;
        string x="";
        int ind=0;
        
        unordered_map<char,string> mpp1;
        unordered_map<string,char> mpp2;
        
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
                x+=s[i];
            else
            {
                str.push_back(x);
                x="";
            }
            
        }
        
        if(str.size()!=pattern.size())
            return false;
        
        
        for(int i=0;i<pattern.size();i++)
        {
            if(mpp1.find(pattern[i])==mpp1.end())
            {
                mpp1[pattern[i]]=str[i];
            }
            
            else if(mpp1[pattern[i]]!=str[i])
                return false;
            if(mpp2.find(str[i])==mpp2.end())
            {
                mpp2[str[i]]=pattern[i];
            }
            else if(mpp2[str[i]]!=pattern[i])
                return false;
        }
       
      
        
     
        return true;
        
    }
};