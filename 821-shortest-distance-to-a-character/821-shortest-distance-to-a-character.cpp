class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        
        vector<int> ans;
        
        int lastInd = INT_MAX;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==c)
                lastInd = i;
            
           if(lastInd == INT_MAX)
               ans.push_back(INT_MAX);
            else
                ans.push_back(abs(i-lastInd));
        }
        
        lastInd = INT_MAX;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]==c)
                lastInd = i;
            
            
            if(lastInd != INT_MAX)
                ans[i] = min(ans[i] , abs(i-lastInd));
        }
        
        return ans;
        
    }
};