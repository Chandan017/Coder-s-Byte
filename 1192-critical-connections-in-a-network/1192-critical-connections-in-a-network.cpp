class Solution {
public:
    vector<vector<int>> ans;
    vector<int> low , time;
    vector<bool> vis;
    
    void dfs(int node , int parent , vector<vector<int>> &adj , int timer)
    {
     
        low[node] = time[node] = timer++;
        timer++;
        vis[node] = true;
        
        for(auto it:adj[node])
        {
            if(it==parent)
                continue;
            if(!vis[it])
            {
                dfs(it , node , adj , timer);
                low[node] = min(low[node] , low[it]);
                
                if(low[it] > time[node])
                    ans.push_back({it , node});
            }
            else
                low[node] = min(low[node] , time[it]);
        }
        return ;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        time.resize(n) , low.resize(n) , vis.resize(n,false);
        
        vector<vector<int>> adj(n);
        
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int timer = 0 ;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i , -1 , adj , timer);
            }
        }
        
        return ans;
    }
};