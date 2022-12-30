class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1 , 0);
        
        for(auto it:relations)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        
        queue<pair<int,int>> q;
        vector<int> cTime(n , 0);
        
        for(int i=1;i<=n;i++)
        {
            if(indegree[i] == 0)
                q.push({i,0});
        }
        
    
        
        while(q.size())
        {
            int node = q.front().first;
            int currTime = q.front().second;
            q.pop();
            
            int currTotal = currTime + time[node-1];
            
            cTime[node-1] = currTotal;
            
            for(auto it:adj[node])
            {
                cTime[it-1] = max(cTime[it-1] , currTotal);
                indegree[it]--;
                
                if(indegree[it] == 0)
                    q.push({it , cTime[it-1]});
            }
        }
        
        int res = *max_element(cTime.begin() , cTime.end());
        return res;
        
    }
};