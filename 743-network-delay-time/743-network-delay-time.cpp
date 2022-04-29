class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int , int>> adj[n+1];
        
        for(auto it:times)
        {
            int u = it[0] , v = it[1] , t = it[2];
            
            adj[u].push_back({v , t});
        }
        
        queue<pair<int , int>> q;
        q.push({k , 0});
        int maxTime = -1 , visitedNodes = 0;
        vector<int> vis(n+1 , INT_MAX);
        vis[k] = 0;
        while(!q.empty())
        {
            int currNode = q.front().first;
            int currTime = q.front().second;
            q.pop();
        
            
            for(auto it:adj[currNode])
            {
                if(vis[it.first] > currTime + it.second)
                {
                    q.push({it.first , currTime + it.second});
                    vis[it.first] = currTime + it.second;
                }
                
            }
        }
        
        for(auto it:vis)
            cout<<it<<" ";
        cout<<endl;
        
        for(int i=1;i<n+1;i++)
        {
            if(vis[i]==INT_MAX)
                return -1;
            else
                maxTime = max(maxTime , vis[i]);
        }
        
        
        return maxTime;
        
    }
};