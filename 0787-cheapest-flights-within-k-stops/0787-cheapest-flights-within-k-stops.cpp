class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1] , it[2]});
        }
        
        vector<int> totalDist(n , INT_MAX);
        queue<vector<int>> q;
        q.push({0 , src , 0});
        totalDist[src] = 0;
        
        while(q.size())
        {
            int len = q.size();
            while(len--)
            {
                int currDist = q.front()[2];
                int currStops = q.front()[0];
                int node = q.front()[1];
                q.pop();
                
                if(currStops > k)
                    continue;
                
                for(auto it:adj[node])
                {
                    int adjNode = it.first;
                    int cost = it.second;
                    if(cost + currDist < totalDist[adjNode])
                    {
                        totalDist[adjNode] = cost + currDist;
                        q.push({currStops+1 , adjNode , totalDist[adjNode]});
                    }
                }
            }
        }
        
        
        
        if(totalDist[dst] == INT_MAX)
            return -1;
        
        return totalDist[dst];
        
    }
};