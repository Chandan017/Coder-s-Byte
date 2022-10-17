class Solution {
public:
    int minSteps(string s, string t) {
        
        vector<int> vis(26,0);
        
        for(auto &c:s)
            vis[c-'a']++;
        
        for(auto &c:t)
        {
            if(vis[c-'a'] > 0)
                vis[c-'a']--;
        }
        
        int totalConversions = 0;
        
        for(auto it:vis)
            totalConversions += it;
        
        return totalConversions;
        
    }
};