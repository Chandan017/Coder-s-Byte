class Solution {
public:
    
    map<char,int> getHash(string &s)
    {
        map<char,int> mpp;
        
        for(auto &it:s)
        {
            mpp[it]++;
        }
        
        return mpp;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<map<char,int> , vector<string>> mpp;
        vector<vector<string>> ans;
        
        int n=strs.size();
        for(int i=0;i<n;i++)
        {
            map<char , int> temp=getHash(strs[i]);
            
            mpp[temp].push_back(strs[i]);
        }
        
        
        for(auto &it:mpp)
        {
            ans.push_back(it.second);
        }
        
        
        
        return ans;
        
    }
};