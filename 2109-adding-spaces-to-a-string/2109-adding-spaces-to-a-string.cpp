class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        string ans = "";
        int n = s.length();
        int ptr = 0;
        
        for(int i=0;i<n;i++)
        {
            if( ptr < spaces.size() && i==spaces[ptr])
            {
                ptr++;
                ans += ' ';
            }
            
            ans += s[i];
        }
        
        return ans;
        
    }
};