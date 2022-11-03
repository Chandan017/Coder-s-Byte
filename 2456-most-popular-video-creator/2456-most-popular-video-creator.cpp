class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        
        vector<vector<string>> res;
        
        unordered_map<string,long> mpp;
        
        int n = ids.size();
        
        long maxView = 0;
        for(int i=0;i<n;i++)
        {
            mpp[creators[i]] += views[i];
            maxView = max(maxView , mpp[creators[i]]);
        }
        
        unordered_map<string,set<pair<int,string>>> temp;
        
        for(int i=0;i<n;i++)
        {
            temp[creators[i]].insert({ -views[i] ,ids[i]});
        }
        
        
        
        for(int i=0;i<n;i++)
        {
            if(mpp[creators[i]] == maxView)
            {
                
                auto curr = temp[creators[i]].begin();
                
                res.push_back({creators[i] , curr->second});
                mpp[creators[i]] = -1;
            }
        }
        
        
        
        return res;
        
    }
};