class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        
        vector<vector<int>> adj(n+1);
        
        
        vector<int> indegree(n+1 , 0);
        
        for(auto it:relations)
        {
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        
        queue<int> q;
        
        for(int i=1;i<=n;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        int minTime = 0 , takenCourses = 0;
        
        while(q.size())
        {
            int len = q.size();
            while(len--)
            {
                int curr = q.front();
                q.pop();
                takenCourses++;
                for(auto it:adj[curr])
                {
                    indegree[it]--;
                    
                    if(indegree[it] == 0)
                    {
                        q.push(it);
                    }
                }
            }
            
            minTime++;
        }
        
        if(takenCourses != n)
            return -1;
        return minTime;
        
        
    }
};