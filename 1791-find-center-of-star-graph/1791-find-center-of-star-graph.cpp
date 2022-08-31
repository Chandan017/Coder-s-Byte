class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int> degree(n+1);
        
        for(auto it:edges)
        {
            degree[it[0]-1]++;
            degree[it[1]-1]++;
        }
        
        for(int i=0;i<=n;i++)
        {
            if(degree[i] == n)
                return i+1;
        }
        
        return -1;
        
    }
};