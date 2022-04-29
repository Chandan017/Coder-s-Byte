class Solution {
public:
    
    bool check(int node , vector<int> &col , vector<vector<int>> &graph)
    {
        queue<pair<int,int>> q;
        q.push({node , 0});
        col[node] = 0;
        
        while(!q.empty())
        {
            int node = q.front().first;
            int color = q.front().second;
            q.pop();
            
            for(auto it:graph[node])
            {
                if(col[it]==-1)
                {
                    q.push({it , !color});
                    col[it] = !color;
                }
                else if(col[it] == color)
                    return false;
            }
            
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int v = graph.size();
        
        vector<int> col(v+1 , -1);
        
        for(int i=0;i<v;i++)
        {
            if(col[i] == -1)
            {
                if(check(i , col , graph) == false)
                    return false;
            }
        }
        return true;
    }
};