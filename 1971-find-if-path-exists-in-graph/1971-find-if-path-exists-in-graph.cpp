class Solution {
public:
    bool check(int node , int dest , vector<vector<int>> &adj , vector<bool> &vis)
    {
        vis[node] = true;
        if(node == dest)
            return true;
        
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(check(it , dest , adj , vis))
                    return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> adj(n);
        
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<bool> vis(n  , false);
        
        if(check(source , destination , adj , vis))
            return true;
        
        return false;
        
    }
};