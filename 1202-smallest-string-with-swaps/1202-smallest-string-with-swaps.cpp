class Solution {
public:
    
    void dfs(int node ,  priority_queue<char , vector<char> , greater<char> > &pq , vector<bool> &vis , vector<int> &parent , int &component , vector<vector<int>> &adj , string &s)
    {
        vis[node] = true;
        parent[node] = component;
        pq.push(s[node]);
        
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it , pq , vis , parent , component , adj , s);
            }
        }
        
        return ;
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n = s.length();
        vector<vector<int>> adj(n+1);
        
        for(auto &it:pairs)
        {
            int x = it[0] , y = it[1];
            
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        vector<bool> vis(n, false);
        vector<int> parent(n);
        iota(parent.begin() , parent.end() , 0);
        
        map<int ,  priority_queue<char , vector<char> , greater<char>> > mpp;
        int component = 0;
        
        for(int i =0;i < n;i++)
        {
            if(!vis[i])
            {
                 priority_queue<char , vector<char> , greater<char> > pq;
                
                dfs(i , pq , vis , parent , component , adj , s);
                
                mpp[component] = pq;
                
                component++;
            }
        }
        
        string ans = "";
        
        for(int i =0; i<n ;i++)
        {
            int key = parent[i];
            
            char x = mpp[key].top();
            mpp[key].pop();
            
            ans += x;
        }
        
        return ans;
    }
};