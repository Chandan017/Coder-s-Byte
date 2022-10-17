class Solution {
public:
    int minSteps(string s, string t) {
        
        unordered_map<char,int> mpp;
        
        for(auto &c:s)
        {
            mpp[c]++;
        }
        
        for(auto &c:t)
        {
            if(mpp.find(c) != mpp.end() && mpp[c] > 0)
                mpp[c]--;
        }
        
        int totalConversions = 0;
        
        for(auto it:mpp)
            totalConversions += it.second;
        
        return totalConversions;
        
    }
};