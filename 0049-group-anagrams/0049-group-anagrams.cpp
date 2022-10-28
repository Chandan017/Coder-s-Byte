class Solution {
public:
    
    vector<int> getFreq(string &s)
    {
        vector<int> freq(26,0);
        
        for(auto it:s)
            freq[it-'a']++;
        
        return freq;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<vector<int> , vector<string>> mpp;
        for(auto it:strs)
        {
            vector<int> freq = getFreq(it);
            
            mpp[freq].push_back(it);
        }
        
        vector<vector<string>> res;
        
        for(auto it:mpp)
        {
            res.push_back(it.second);
        }
        
        return res;
        
    }
};