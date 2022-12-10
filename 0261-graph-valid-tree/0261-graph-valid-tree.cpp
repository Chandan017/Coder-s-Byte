class Solution {
public:
    
    bool checkCycle(int node , int parent , vector<vector<int>> &adj , vector<bool> &vis)
    {
        if(vis[node])
            return true;
        
        vis[node] = true;
        
        for(auto it:adj[node])
        {
            if(it != parent)
            {
                bool curr = checkCycle(it , node , adj , vis);
                if(curr)
                    return true;
            }
        }
        
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        
        
        vector<vector<int>> adj(n);
        
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<bool> vis(n, false);
        
        bool hasCycle = checkCycle(0 , -1 , adj , vis);
        
        for(auto it:vis)
            if(!it)
                return false;
        
        if(hasCycle)
            return false;
        
        return true;
        
    }
};