class Solution {
public:
    
    bool check(int node , vector<bool> &vis , vector<bool> &pathVis , vector<int> adj[])
    {
        vis[node] = true;
        pathVis[node] = true;
        
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(check(it , vis , pathVis , adj))
                    return true;
            }
            else if(pathVis[it] && vis[it])
                return true;
        }
        
        pathVis[node] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<bool> vis(numCourses , false);
        vector<bool> pathVis(numCourses , false);
        
        vector<int> adj[numCourses];
        
        for(auto it:prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }
        
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(check(i , vis , pathVis , adj))
                    return false;
            }
        }
        
        return true;
        
    }
};