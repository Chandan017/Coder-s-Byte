class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n=graph.size();
        
        queue<pair<int,vector<int>>> q;
        vector<int> temp;
        temp.push_back(0);
        q.push({0 , temp});
        
        vector<vector<int>> ans;
        
        while(!q.empty())
        {
            int node=q.front().first;
            vector<int> path=q.front().second;
            q.pop();
            
            if(node==n-1)
            {
                ans.push_back(path);
                continue;
            }
            
            for(auto it:graph[node])
            {
                path.push_back(it);
                q.push({it , path});
                path.pop_back();
            }
            
        }
        
        return ans;
        
    }
};