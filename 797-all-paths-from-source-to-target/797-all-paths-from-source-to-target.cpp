class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<vector<int>> ans;
        
        vector<int> adj[n];
        
        for(int i=0;i<n;i++)
        {
            for(auto &it:graph[i])
                adj[i].push_back(it);
        }
        
        
        
        vector<int> temp;
        temp.push_back(0);
        
        queue<pair<int,vector<int>>> q;
        q.push({0,temp});
        
        
        while(!q.empty())
        {
            int ind=q.front().first;
            vector<int> temp=q.front().second;
            q.pop();
            
            if(ind==n-1)
            {
                ans.push_back(temp);
            }
            
            for(auto &it:adj[ind])
            {
                temp.push_back(it);
                q.push({it,temp});
                temp.pop_back();
            }
        }
        
        
        
        
        
        
        
        return ans;
        
        
    }
};