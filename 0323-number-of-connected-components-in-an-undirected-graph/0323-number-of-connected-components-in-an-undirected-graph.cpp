class Solution {
public:
    
    void markAll(int node , vector<vector<int>> &adj , vector<bool> &vis)
    {
        vis[node] = true;
        
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                markAll(it , adj , vis);
            }
        }
        
        return ;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        int components = 0;
        
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                components++;
                markAll(i , adj , vis);
            }
        }
        
        return components;
        
    }
};