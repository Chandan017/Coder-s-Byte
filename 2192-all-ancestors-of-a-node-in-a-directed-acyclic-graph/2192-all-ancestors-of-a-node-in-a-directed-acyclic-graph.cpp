class Solution {
public:
     vector<int> adj[1000];
    vector<int> getAll(int node)
    {
        
        vector<int> ans;
        
        set<int> s;
        queue<int> q;
        q.push(node);
        
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            
            for(auto &it:adj[x])
            {
                if(s.find(it)==s.end())
                {
                    s.insert(it);
                    q.push(it);
                }
            }
        }
        
        for(auto &it:s)
            ans.push_back(it);
        return ans;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        
       
        int size=-1;
        for(int i=0;i<edges.size();i++)
        {
            int from=edges[i][0];
            int to=edges[i][1];
            
            adj[to].push_back(from);  // transpose
            
            size=max(size,to);
        }
        
        vector<vector<int>> ans;
        
        for(int i=0;i<=size;i++)
        {
            vector<int> temp=getAll(i);
            
            ans.push_back(temp);
        }
        
        while(ans.size()!=n)
        {
            vector<int> temp;
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};