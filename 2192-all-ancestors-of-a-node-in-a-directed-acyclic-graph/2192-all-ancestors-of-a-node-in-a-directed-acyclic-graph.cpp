class Solution {
public:
    
    
    vector<int> getAll(int node , vector<int> adj[])
    {
        
        vector<int> ans;
        
        set<int> s;
        queue<int> q;
        q.push(node);
        
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            
            for(auto &it:adj[x])
            {
                if(s.find(it)==s.end())
                {
                    s.insert(it);
                    q.push(it);
                }
            }
        }
        
        for(auto &it:s)
            ans.push_back(it);
        return ans;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        
       
         vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            int from=edges[i][0];
            int to=edges[i][1];
            
            adj[to].push_back(from);  // transpose
            
        }
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++)
        {
            vector<int> temp=getAll(i,adj);
            
            ans.push_back(temp);
        }
        

        return ans;
        
    }
};