class Solution {
public:
    
    vector<vector<int>> res;
    
    void solve(int node , vector<vector<int>> &adj , vector<int> path , int dest)
    {
        path.push_back(node);
        
        if(node == dest)
        {
            res.push_back(path);
            return ;
        }
        
        for(auto it:adj[node])
        {
            solve(it , adj , path , dest);
        }
        return ;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        // vector<vector<int>> adj(n);
        // for(auto it:graph)
        // {
        //     adj[it[0]].push_back(it[1]);
        // }
        
        vector<int> path;
        solve(0 , graph , path , n-1);
        
        return res;
    }
};