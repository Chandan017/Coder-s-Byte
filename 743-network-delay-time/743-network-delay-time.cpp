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
        vector<int> time(n+1 , INT_MAX);
        time[k] = 0;
        while(!q.empty())
        {
            int currNode = q.front().first;
            int currTime = q.front().second;
            q.pop();
        
            
            for(auto it:adj[currNode])
            {
                if(time[it.first] > currTime + it.second)
                {
                    q.push({it.first , currTime + it.second});
                    time[it.first] = currTime + it.second;
                }
                
            }
        }
              
        for(int i=1;i<n+1;i++)
        {
            if(time[i]==INT_MAX)
                return -1;
            else
                maxTime = max(maxTime , time[i]);
        }
        
        
        return maxTime;
        
    }
};