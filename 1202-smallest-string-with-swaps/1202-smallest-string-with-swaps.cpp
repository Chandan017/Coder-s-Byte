class Solution {
public:
    
    void dfs(int node ,priority_queue<char , vector<char> , greater<char> > &pq ,  vector<bool> &vis , string &s , vector<int> adj[] , vector<int> &parent , int &component)
    {
        vis[node] = true;
        parent[node] = component;
        pq.push(s[node]);
        for(auto it:adj[node])
        {
            if(!vis[it])
                dfs(it , pq , vis , s , adj , parent , component);
        }
        
        return ;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n = s.length();
        
        vector<int> adj[n];
        
        for(auto it:pairs)
        {
            int x = it[0];
            int y = it[1];
            
            adj[x].push_back(y);
            adj[y].push_back(x);
            
        }
        
        vector<bool> vis(n , false);
        vector<int> parent(n);
        map<int , priority_queue<char , vector<char> , greater<char> > > mpp;
        iota(parent.begin() , parent.end() , 0);
        int component = 0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                priority_queue<char , vector<char> , greater<char> > pq;
                
                dfs(i , pq , vis , s , adj , parent , component);
                
                mpp[component] = pq;
                
                component++; 
            }
        }
        
        string ans = "";
        
        for(int i =0;i<n;i++)
        {
            int key = parent[i];
            
            char x = mpp[key].top();
            mpp[key].pop();
            
            ans += x;
        }
        
        return ans;
        
    }
};