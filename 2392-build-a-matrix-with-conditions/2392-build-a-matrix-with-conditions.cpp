class Solution {
public:
    
    vector<int> kahn(int k , vector<vector<int>> &edges)
    {
        vector<int> indegree(k+1 , 0);
        vector<vector<int>> adj(k+1);
        
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        
        queue<int> q;
        vector<int> topoSort;
        
        for(int i=1;i<=k;i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(q.size())
        {
            int node = q.front();
            q.pop();
            
            topoSort.push_back(node);
            
            for(auto it:adj[node])
            {
                indegree[it]--;
                
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        
        
        return topoSort;
        
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        
        vector<int> row = kahn(k , rowConditions);
        vector<int> col = kahn(k , colConditions);
        
        if(row.size() != k || col.size() != k)
            return {};
        
        vector<vector<int>> res(k , vector<int> (k,0));
        vector<int> index(k+1 , 0);
        
        for(int i=0;i<k;i++)
            index[col[i]] = i;
        
        for(int i=0;i<k;i++)
            res[i][index[row[i]]] = row[i];
        
        return res;      
    }
};