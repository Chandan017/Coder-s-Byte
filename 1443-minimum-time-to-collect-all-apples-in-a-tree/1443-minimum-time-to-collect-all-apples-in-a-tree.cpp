class Solution {
public:
    
    int solve(int node , int parent , vector<vector<int>> &adj , vector<bool> &hasApple)
    {
        int totalTime = 0 , childTime = 0;
        
        for(auto &it:adj[node])
        {
            if(it != parent)
            {
                childTime = solve(it , node , adj , hasApple);
            
            if(childTime != 0 || hasApple[it])
                totalTime += (childTime + 2);
            }
        }
        
        
        return totalTime;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<vector<int>> adj(n);
        
        for(auto &it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int res = solve(0 , -1 , adj , hasApple);
        
        return res;
        
    }
};