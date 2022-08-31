class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        map<int,int> mpp;
        int n = edges.size();
        
        for(auto it:edges)
        {
            mpp[it[0]]++;
            mpp[it[1]]++;
        }
        
        for(auto it:mpp)
        {
            if(it.second == n)
                return it.first;
        }
        
        return -1;
        
    }
};