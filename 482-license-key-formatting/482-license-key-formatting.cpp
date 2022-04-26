class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        
        string ans = "";
        int n = s.length();
        int i=n-1;
        while(i>=0)
        {
            int cnt = 0;
            while(cnt < k  && i>=0)
            {
                if(s[i]=='-')
                {
                    i--;
                    continue;
                }
                
                if(islower(s[i]))
                {
                    s[i] = toupper(s[i]);
                }
                ans += s[i];
                cnt++;
                i--;
            }
            ans += '-';
        }
        
        while(ans.back()=='-')
            ans.pop_back();
        reverse(ans.begin() , ans.end());
        
        return ans;
        
    }
};