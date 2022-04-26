class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        
        string ans = "";
        int n = s.length();
        int cnt = 0;
        
        for(int i=n-1;i>=0;i--)
        {
            if(s[i] != '-')
            {
                if(cnt == k)
                {
                    cnt = 0;
                    ans += '-';
                }
                
                ans += toupper(s[i]);
                
                cnt++;
            }
        }
        
        
        
        reverse(ans.begin() , ans.end());
        
        return ans;
        
    }
};