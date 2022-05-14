class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>> adj[n+1];
        
        for(auto it:times)
        {
            int u = it[0] , v = it[1] , wt = it[2];
            
            adj[u].push_back({v , wt});
        }
        vector<int> dist(n+1 , INT_MAX);
        dist[k] = 0;
        queue<pair<int,int>> q;
        q.push({k,0});
        
        int nodesCovered = 0;
        int maxTime = 0;
        
        while(!q.empty())
        {
            int len = q.size();
            
            while(len--)
            {
                int node = q.front().first;
                int currDist = q.front().second;
                q.pop();
                
            
                for(auto it:adj[node])
                {
                    int newDist = currDist + it.second;
                    
                    if(dist[it.first] > newDist)
                    {
                        dist[it.first] = newDist;
                        q.push({it.first , newDist});
                    }
                }
                    
                
            }
        }
        
        
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)
                return -1;
            else
                maxTime = max(maxTime , dist[i]);
        }
        
        return maxTime;
        
    }
};