class Solution {
public:
    
    bool fill(int node , vector<vector<int>> &adj , vector<int> &col)
    {
        col[node] = 0;
        
        queue<int> q;
        q.push(node);
        bool currColor = 1;
        
        while(q.size())
        {
            int len = q.size();
            while(len--)
            {
                int node = q.front();
                q.pop();
                // cout<<node<<"->"<<col[node]<<endl;
                
                for(auto it:adj[node])
                {
                    if(col[it] == -1)
                    {
                        col[it] = currColor;
                        q.push(it);
                    }
                    else if(col[it] != currColor)
                        return false;
                    
                }
            }
            
            currColor = !currColor;
        }
        
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<vector<int>> adj(n+1);
        
        for(auto it:dislikes)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> col(n+1 , -1);
        
        bool canFill = true;
        
        for(int i=1;i<=n;i++)
        {
            if(col[i] == -1)
            {
                bool curr = fill(i , adj , col);
                // return true;
                
                if(!curr)
                {
                    // cout<<i<<endl;
                    return false;
                }
            }
        }
        cout<<endl;
        // if(!canFill)
        //     return false;
        
        return true;
        
    }
};