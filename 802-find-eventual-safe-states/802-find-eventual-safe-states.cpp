class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        
        int n=graph.size();
        vector<int> adj[n];
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            for(auto &it:graph[i])
                adj[it].push_back(i);
        }
        
        vector<int> indegree(n,0);
        queue<int> q;
        
        for(int i=0;i<n;i++)
        {
            for(auto &it:adj[i])
                indegree[it]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
       
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto &it:adj[node])
            {
                indegree[it]--;
                
                if(indegree[it]==0)
                    q.push(it);
            }
        }
            
        
        sort(ans.begin() , ans.end());
        
        
        return ans;
        
    }
};