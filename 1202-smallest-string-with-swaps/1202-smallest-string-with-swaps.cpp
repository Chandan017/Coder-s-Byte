class Solution {
public:
    
    void dfs(int node ,multiset<char> &pq ,  vector<bool> &vis , string &s , vector<int> adj[] , vector<int> &parent , int &component)
    {
        vis[node] = true;
        parent[node] = component;
        pq.insert(s[node]);
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
        map<int , multiset<char> > mpp;
        iota(parent.begin() , parent.end() , 0);
        int component = 0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                multiset<char> pq;
                
                dfs(i , pq , vis , s , adj , parent , component);
                
                mpp[component] = pq;
                
                component++; 
            }
        }
        
        string ans = "";
        
        for(int i =0;i<n;i++)
        {
            int key = parent[i];
            
            multiset<char> &temp = mpp[key];
            char x = *temp.begin();
            
            temp.erase(temp.begin());
            
            ans += x;
        }
    
        return ans;
        
    }
};