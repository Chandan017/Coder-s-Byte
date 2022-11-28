class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        map<int,int> mpp;
        
        for(auto it:matches)
        {
            if(mpp.find(it[0]) == mpp.end())
                mpp[it[0]] = 0;
            
            mpp[it[1]]++;
        }
        
        vector<vector<int>> res(2);
        
        for(auto it:mpp)
        {
            if(it.second == 0)
                res[0].push_back(it.first);
            else if(it.second == 1)
                res[1].push_back(it.first);
        }
        
        sort(res[0].begin() , res[0].end());
        sort(res[1].begin() , res[1].end());
        
        return res;
        
    }
};