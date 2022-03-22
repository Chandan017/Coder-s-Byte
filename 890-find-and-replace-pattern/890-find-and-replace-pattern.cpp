class Solution {
public:
    
    bool check(string &s1 , string &s2)
    {
        vector<char> mpp1(26,'0') , mpp2(26,'0');
        int n=s1.length();
        
        for(int i=0;i<n;i++)
        {
            if(mpp1[s1[i]-'a']=='0')
                mpp1[s1[i]-'a']=s2[i];
            else if(mpp1[s1[i]-'a']!=s2[i])
                return false;
            
            if(mpp2[s2[i]-'a']=='0')
                mpp2[s2[i]-'a']=s1[i];
            else if(mpp2[s2[i]-'a']!=s1[i])
                return false;
        }
        
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;

        for(auto it:words)
        {
            bool isValid=check(it , pattern);
            
            if(isValid)
                ans.push_back(it);
            
        }
        
        return ans;
        
    }
};