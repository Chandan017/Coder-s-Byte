class Solution {
public:
    string greatestLetter(string s) {
        
        int n = s.length();
        
        vector<bool> small(26,false);
        vector<bool> caps(26,false);
        
        for(int i=0;i<n;i++)
        {
            if(s[i] >='A' && s[i]<='Z')
                caps[s[i]-'A'] = true;
            else
                small[s[i]-'a'] = true;
        }
        
        string ans = "";
        
        for(int i=0;i<26;i++)
        {
            if(caps[i] && small[i] &&  (ans=="" || ans[0] < (i+'A')))
            {
                if(ans != "")
                    ans.pop_back();
                ans += (i+'A');
            }
        }
        
        return ans;
        
    }
};