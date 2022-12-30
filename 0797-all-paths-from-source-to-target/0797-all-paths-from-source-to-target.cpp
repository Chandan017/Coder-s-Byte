class Solution {
public:
    
    vector<vector<int>> res;
    
    void solve(int node , vector<vector<int>> &adj , vector<int> &path , int dest)
    {
        path.push_back(node);
        
        if(node == dest)
        {
            res.push_back(path);
            path.pop_back();
            return ;
        }
        
        for(auto it:adj[node])
        {
            solve(it , adj , path , dest);
        }
        
        path.pop_back();
        
        return ;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<int> path;
        solve(0 , graph , path , n-1);
        
        return res;
    }
};