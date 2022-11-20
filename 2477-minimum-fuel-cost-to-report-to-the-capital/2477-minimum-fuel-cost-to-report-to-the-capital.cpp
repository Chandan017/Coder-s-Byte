class Solution {
public:
    long long res = 0;
    
    int solve(int node , vector<vector<int>> &adj , vector<bool> &vis , int seats)
    {
        vis[node] = true;
        long long cnt = 1;
        
        for(auto it:adj[node])
        {
            if(!vis[it])
                cnt += solve(it , adj , vis , seats);
        }
        
        if(node != 0)
        {
            res += (cnt/seats);
            
            if(cnt%seats)
                res++;
        }
        
        return cnt;
    }
    
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        int n = roads.size();
        vector<vector<int>> adj(n+1);
        
        for(auto it:roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<bool> vis(n+1 , false);
        
        solve(0 , adj , vis , seats);
        
        return res;
    }
};