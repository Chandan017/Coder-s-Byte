class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        vector<int> vis(26,0);
        int cnt = 0;
        
        for(auto c:sentence)
        {
            if(vis[c-'a'] == 0)
            {
                cnt++;
            }
            
            vis[c-'a']++;
        }
        
        return (cnt==26);
        
    }
};